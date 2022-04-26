<?php

/**
 * @file
 * Returns the HTML for ECK Service configuration Weed ID.
 */
?>

<article class="<?php print $classes; ?> service_configuration__weed_id clearfix"<?php print $attributes; ?>>
  <?php /* BEGIN printing IMAGE. */ ?>
  <div class="weed_id__image">
    <?php print render($content['field_service_weed_id_image']); ?>
  </div>
  <?php /* END printing IMAGE. */ ?>

  <div class="weed_id__info">
    <?php /* BEGIN printing TITLE. */ ?>
    <header>
      <?php if (!$page && $title): ?>
        <?php print render($title_suffix); ?>
          <h2 class="weed_id__title">
            <?php print $title; ?>
          </h2>
        <?php print render($title_suffix); ?>
      <?php endif; ?>
    </header>
    <?php /* END printing TITLE. */ ?>

    <?php /* BEGIN printing DESCRIPTION. */ ?>
    <div class="weed_id__text">
      <?php print render($content['field_service_weed_id_descriptio']); ?>
    </div>
    <?php /* END printing DESCRIPTION. */ ?>
  </div>
</article>
