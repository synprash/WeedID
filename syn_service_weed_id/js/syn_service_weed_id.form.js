/**
 * @file
 * Contains javascripts related to Service Weed ID.
 */

(function ($) {
  /**
   * Handles fieldset - collapsing, adding title.
   */
  Drupal.behaviors.synServiceWeedIdFieldset = {
    attach: function () {
      // Collapse other fieldsets when expanding one.
      $('#filter-criterias .fieldset-title:not(.syn-collapse-processed)').on('click', function (event, additional) {
        if (additional !== 'syn_service_weed_id_skip_event' && !$(this).parents('fieldset').hasClass('collapsed')) {
          var $this = $(this);
          $('#filter-criterias .fieldset-title').each(function () {
            if ($(this) !== $this && !$(this).parents('fieldset').hasClass('collapsed')) {
              $(this).trigger('click', ['syn_service_weed_id_skip_event']);
            }
          });
        }
      }).addClass('syn-collapse-processed');
      // Sets title to the fieldset legend.
      $('#filter-criterias fieldset:not(.syn-title-processed)').each(function () {
        $(this)
          .find('legend:first').attr('title', $(this).attr('title'))
          .removeAttr('title')
          .addClass('syn-title-processed');
      });
      // Toggle effect for weed id step 4.
      $('.weedid-step-four .weed-id-compare-container').click(function () {
          $('.weedid-step-four .views-field-view').toggle();
          $('.weedid-step-four .views-field-view-1').toggle();
          $('.weedid-step-four .views-field-view-2').toggle();
      });
      $('.weedid-step-four .weed-id-compare-container a').on("click", function (e) {
          e.preventDefault();
      });
      // Tooltip effect for weed id step 2.
      $('.weedid-step-two .views-field-nothing-1').hover(function () {
        $(this).prev().animate({
          opacity: "1"
        }, {
          queue: false
        });
        }, function () {
        $(this).prev().animate({
          opacity: "0"
        }, {
          queue: false
        });
      });
    }
  };
  /**
   * Handles adding or removing weed criterias.
   */
  Drupal.behaviors.synServiceWeedIdAddRemoveCriteria = {
    attach: function () {
      // Add new criteria.
      $('div.service-weed-id-add:not(.syn-add-criteria-processed)').on('click', function () {
        $('input[name="added_criteria"]').val($(this).attr('data-tid'));
        $('input[name="step_2__add_criteria"]')
        // Move to the + wrapper to show the loader there.
          .appendTo($(this))
          .trigger('mousedown');
      }).addClass('syn-add-criteria-processed');
      // Remove criteria.
      $('div.service-weed-id-remove:not(.syn-remove-criteria-processed)').on('click', function () {
        $('input[name="removed_criteria"]').val($(this).attr('data-tid'));
        $('input[name="step_2__remove_criteria"]')
        // Move to the x wrapper to show the loader there.
          .appendTo($(this))
          .trigger('mousedown');
      }).addClass('syn-remove-criteria-processed');
    }
  };
  /**
   * Handles choosing of targets for comparison.
   */
  Drupal.behaviors.synServiceWeedIdChooseComparisonTargets = {
    attach: function (context, settings) {
      if (
        // If we are going from other step than third and the comparison targets
        // are populated we reset them.
        (
          typeof settings.syn_service_weed_id.comparison_targets !== 'undefined' &&
          (typeof settings.syn_service_weed_id.step !== 'number' || settings.syn_service_weed_id.step !== 3)
        ) ||
        // If comparison targets are undefined we instantiate them.
        typeof settings.syn_service_weed_id.comparison_targets === 'undefined'
      ) {
        settings.syn_service_weed_id.comparison_targets = {};
      }
      $('input.weed-id-compare:not(.syn-choose-comparison-processed)').each(function () {
        if (
          typeof settings.syn_service_weed_id.comparison_targets[$(this).val()] !== 'undefined' &&
          $(this).not(':checked')
        ) {
          $(this).trigger('click');
        }
      });
      // Adding/removing new targets for comparison.
      $('input.weed-id-compare:not(.syn-choose-comparison-processed)').on('click', function () {
        // Based on check or uncheck of the comparison checkbox we add/remove
        // targets for comparison.
        if ($(this).is(':checked')) {
          settings.syn_service_weed_id.comparison_targets[$(this).val()] = $(this).val();
        }
        else {
          delete(settings.syn_service_weed_id.comparison_targets[$(this).val()]);
        }
        // If the targets are two we go to step 4.
        if (Object.keys(settings.syn_service_weed_id.comparison_targets).length === 2) {
          $('input[name="comparison_targets"]').val(JSON.stringify(settings.syn_service_weed_id.comparison_targets));
          $('input[name="step_3__compare"]')
          // Move to the x wrapper to show the loader there.
            .appendTo($(this).parents('label'))
            .trigger('mousedown');
        }
      }).addClass('syn-choose-comparison-processed');
    }
  };
  /**
   * Scrolls to the specified element on going threw steps.
   */
  Drupal.behaviors.synServiceWeedIdScrollTo = {
    attach: function (context, settings) {
      // If we have received weed id settings scroll and the element exists we
      // scroll to this html element.
      if (
        typeof settings.syn_service_weed_id !== 'undefined' &&
        typeof settings.syn_service_weed_id.scroll !== 'undefined' &&
        $(settings.syn_service_weed_id.scroll).length === 1
      ) {
        // Calculate the scroll height.
        // Get the element scroll top position.
        var scrollTop = $(settings.syn_service_weed_id.scroll).offset().top;
        // Remove the main header (primary menu) height.
        scrollTop -= $('header.main__header').length > 0 ? $('header.main__header').height() : 0;
        // Remove the main navigation height.
        scrollTop -= $('#navbar-bar').length > 0 ? $('#navbar-bar').height() : 0;
        // Remove the main navigation second tray height.
        scrollTop -= $('div.navbar-tray-horizontal').length > 0 ? $('div.navbar-tray-horizontal').height() : 0;
        // Scroll to the element.
        var secondaryMenuHidden = $('div.main__header-wrapper').hasClass('scroll-down-processed');
        $('html, body').animate({scrollTop: scrollTop}, 'normal', 'linear', function () {
          // If the secondary menu was hidden and now is expanded scroll
          // additional.
          if (secondaryMenuHidden && !$('div.main__header-wrapper').hasClass('scroll-down-processed')) {
            $('html, body').animate({scrollTop: scrollTop - 40}, 'normal', 'linear');
          }
          // If the secondary menu was expanded and now is hidden scroll
          // additional.
          else if (!secondaryMenuHidden && $('div.main__header-wrapper').hasClass('scroll-down-processed')) {
            $('html, body').animate({scrollTop: scrollTop + 40}, 'normal', 'linear');
          }
        });
        // Remove the scroll settings.
        delete(settings.syn_service_weed_id.scroll);
      }
    }
  };
})(jQuery);
