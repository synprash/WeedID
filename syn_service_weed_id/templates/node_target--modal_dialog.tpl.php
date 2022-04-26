<?php

/**
 * @file
 * Displays target node inside weed id service popup.
 *
 * Available variables:
 * - $target: The target node.
 * - $target_title: The target title.
 * - $target_global_description: The target global description.
 * - $target_seedling_carousel: The rendered target carousel with images.
 *   $target_adult_carousel: The rendered target carousel with images.
 * - $target_rightside: All the rendered content for the target right side.
 */
?>

<?php /* The container holding the whole content of the modal. */ ?>
<div class="weedid-modal-window two-cols__region">
  <?php /* The container for the left side of the modal. */ ?>
  <div class="panel-pane">
    <?php /* Render the target global description. */ ?>
    <?php print $target_global_description; ?>
    <?php /* Render the target image carousel. */ ?>
    <?php print $target_seedling_carousel; ?>
    <?php print $target_adult_carousel; ?>
  </div>

  <?php /* The container for the right side of the modal. */ ?>
  <div class="panel-pane">
    <?php /* Render the target title. */ ?>

      <div class="weedid-title"><strong><?php print $target_title; ?> ( <?php print $target_details; ?> ) </strong></div>
    <?php /* Render the target right side content. */ ?>
    <?php print $target_rightside; ?>
  </div>
</div>
