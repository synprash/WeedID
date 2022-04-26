/**
 * @file
 * Contains javascripts related to Service Weed ID.
 */

(function ($) {
    /**
     * Provide the HTML to create the modal dialog.
     */
  Drupal.theme.prototype.WeedidModal = function () {
    var html = '';
    html += '<div id="ctools-modal" class="popups-box">';
    html += '  <div class="ctools-modal-content ctools-modal-weedid-modal-content">';
    html += '    <span class="popups-close"><a class="close ctools-close-modal" href="#">X</a></span>';
    html += '    <div class="modal-scroll"><div id="modal-content" class="modal-content popups-body"></div></div>';
    html += '  </div>';
    html += '</div>';
    return html;
  }
})(jQuery);
