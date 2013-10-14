<?php

/**
 * @file
 * Views handler and plugin definitions for the legal module.
 */

/**
 * Implements hook_views_data().
 */
function legal_updates_views_data() {
  $data                                     = array();
  $data['legal_updates_accepted']['table']['group'] = t('Legal Extras');
  $data['legal_updates_conditions']['table']['group'] = t('Legal Extras Fields');
  $data['legal_updates_accepted']['table']['join']['legal_accepted'] = array(
    'left_field' => 'legal_id',
    'field'      => 'legal_id',
  );
  $data['legal_updates_conditions']['table']['join']['legal_conditions'] = array(
    'left_field' => 'version',
    'field'      => 'version',
  );
  $data['legal_accepted']['legal_updates_accepted_rel'] = array(
    'title'        => t('Legal Extras'),
    'group'        => t('Legal Extras'),
    'help'         => t('Extra fields for legal module'),
    'relationship' => array(
      'handler'            => 'views_handler_relationship',
      'base'               => 'legal_updates_accepted',
      'base field'         => 'legal_id',
      'label'              => t('Legal Extras'),
      'relationship field' => 'legal_id',
    ),
  );
  $data['legal_conditions']['legal_updates_conditions_rel'] = array(
    'group'        => t('Legal Extras Fields'),
    'title'        => t('Legal Conditions relationship'),
    'help'         => t('Create a relationship to a legal conditions and legal accepted.'),
    'relationship' => array(
      'handler'            => 'views_handler_relationship',
      'base'               => 'legal_updates_conditions',
      'base field'         => 'version',
      'label'              => t('Legal Extras'),
      'relationship field' => 'version',
    ),
  );
  $data['legal_updates_accepted']['legal_updates_conditions_rel'] = array(
    'group'        => t('Legal Extras Fields'),
    'title'        => t('Legal Conditions relationship'),
    'help'         => t('Create a relationship to a legal conditions and legal accepted.'),
    'relationship' => array(
      'handler'            => 'views_handler_relationship',
      'base'               => 'legal_updates_conditions',
      'base field'         => 'version',
      'label'              => t('Legal Extras'),
      'relationship field' => 'version',
    ),
  );
  $data['legal_updates_accepted']['uid'] = array(
    'title'        => t('User ID'),
    'help'         => t('User ID of user that accepted.'),
    'field'        => array(
      'handler'        => 'views_handler_field_user',
      'click sortable' => TRUE,
    ),
    'filter'       => array(
      'handler'     => 'views_handler_filter_user_name',
      'allow empty' => TRUE,
    ),
    'argument'     => array(
      'handler' => 'views_handler_argument_user_uid',
    ),
    'sort'         => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'base'       => 'users',
      'base_field' => 'uid',
      'handler'    => 'views_handler_relationship',
      'label'      => t('Acceptances to user relationship'),
    ),
  );
  $data['legal_updates_accepted']['ipaddress'] = array(
    'title'    => t('IP Address'),
    'help'     => t('IP Address of the user accepted.'),
    'field'    => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter'   => array(
      'handler'     => 'views_handler_filter_string',
      'allow empty' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort'     => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['legal_updates_accepted']['accepted'] = array(
    'title'  => t('Time Accepted'),
    'help'   => t('Time and date user accepted T&Cs.'),
    'field'  => array(
      'handler'        => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler'     => 'views_handler_filter_date',
      'allow empty' => TRUE,
    ),
    'sort'   => array(
      'handler' => 'views_handler_sort_date',
    ),
  );
  $data['legal_updates_conditions']['extrasfields'] =array(
    'title'    => t('Additional Textfields Label'),
    'help'     => t('Additional terms of T&Cs'),
    'field'    => array(
      'handler'        => 'legal_updates_views_handler_field_unserialized_list',
      'click sortable' => TRUE,
    ),
    'filter'   => array(
      'handler'     => 'views_handler_filter_string',
      'allow empty' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'sort'     => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['legal_updates_conditions']['date'] =array(
    'title'    => t('Additional Textfields Change Time'),
    'help'     => t('Additional terms of T&Cs'),
    'field'    => array(
      'handler'        => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'filter'   => array(
      'handler'     => 'views_handler_filter_date',
      'allow empty' => TRUE,
    ),
    'sort'     => array(
      'handler' => 'views_handler_sort_date',
    ),
  );
  if (module_exists('locale')) {
    $data['legal_updates_conditions']['language'] =array(
      'title'    => t('Additional Textfields Label Language'),
      'help'     => t('Additional terms of T&Cs'),
      'field'    => array(
        'handler'        => 'views_handler_field_locale_language',
        'click sortable' => TRUE,
      ),
      'filter'   => array(
        'handler'     => 'views_handler_filter_locale_language',
        'allow empty' => TRUE,
      ),
      'argument' => array(
        'handler' => 'views_handler_filter_locale_language',
      ),
      'sort'     => array(
        'handler' => 'views_handler_sort',
      ),
    
    );
  }
  $data['legal_updates_accepted']['extrasfields'] =array( 
    'title'    => t('Additional Textfields'),
    'help'     => t('Additional terms of T&Cs'),
    'field'    => array(
      'handler'        => 'legal_updates_views_handler_field_unserialized_list',
      'click sortable' => TRUE,
    ),
    'filter'   => array(
      'handler'     => 'views_handler_filter_string',
      'allow empty' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'sort'     => array(
      'handler' => 'views_handler_sort',
    ),
  );
  return $data;
}