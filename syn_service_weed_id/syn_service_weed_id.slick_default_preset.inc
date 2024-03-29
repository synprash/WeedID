<?php

/**
 * @file
 * syn_service_weed_id.slick_default_preset.inc
 */

/**
 * Implements hook_slick_default_presets().
 */
function syn_service_weed_id_slick_default_presets() {
  $export = array();

  $preset = new stdClass();
  $preset->disabled = FALSE; /* Edit this to true to make a default preset disabled initially */
  $preset->api_version = 1;
  $preset->name = 'weed_id';
  $preset->label = 'Weed-ID';
  $preset->breakpoints = 0;
  $preset->skin = '';
  $preset->options = array(
    'general' => array(
      'normal' => '',
      'thumbnail' => '',
      'template_class' => '',
      'goodies' => array(
        'arrow-down' => 0,
        'pattern' => 0,
        'random' => 0,
      ),
      'arrow_down_target' => '',
      'arrow_down_offset' => '',
    ),
    'settings' => array(
      'mobileFirst' => FALSE,
      'asNavFor' => '',
      'accessibility' => FALSE,
      'adaptiveHeight' => FALSE,
      'autoplay' => FALSE,
      'autoplaySpeed' => 3000,
      'pauseOnHover' => TRUE,
      'pauseOnDotsHover' => FALSE,
      'arrows' => TRUE,
      'prevArrow' => '<button type="button" data-role="none" class="slick-prev owl-prev" aria-label="previous">Previous</button>',
      'nextArrow' => '<button type="button" data-role="none" class="slick-next owl-next" aria-label="next">Next</button>',
      'centerMode' => FALSE,
      'centerPadding' => '0',
      'dots' => FALSE,
      'dotsClass' => 'slick-dots',
      'appendDots' => '$(element)',
      'draggable' => TRUE,
      'fade' => FALSE,
      'focusOnSelect' => FALSE,
      'infinite' => TRUE,
      'initialSlide' => 0,
      'lazyLoad' => 'ondemand',
      'respondTo' => 'window',
      'rtl' => FALSE,
      'rows' => 1,
      'slidesPerRow' => 1,
      'slide' => '',
      'slidesToShow' => 4,
      'slidesToScroll' => 4,
      'speed' => 750,
      'swipe' => TRUE,
      'swipeToSlide' => FALSE,
      'edgeFriction' => 0.34999999999999998,
      'touchMove' => TRUE,
      'touchThreshold' => 20,
      'useCSS' => FALSE,
      'cssEase' => 'ease',
      'cssEaseBezier' => '',
      'cssEaseOverride' => '',
      'useTransform' => FALSE,
      'easing' => 'linear',
      'variableWidth' => FALSE,
      'vertical' => TRUE,
      'verticalSwiping' => TRUE,
      'waitForAnimate' => FALSE,
    ),
  );
  $export['weed_id'] = $preset;

  return $export;
}
