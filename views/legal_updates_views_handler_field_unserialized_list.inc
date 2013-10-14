<?php

/**
 * @file
 * Views fields displaying additional checkboxes.
 */

/**
 * Implementing serialized fields.
 */
class legal_updates_views_handler_field_unserialized_list extends views_handler_field {

  function render($values) {
    $extras = unserialize($values->{$this->field_alias});
    return theme_item_list(array('items' => $extras, 'type' => 'ul'));
  }
}
