'use strict';

var Component = function () {
    function Component(Url, Container, HistoryState) {
        this.Url = Url;
        this.Container = Container;
        this.HistoryState = HistoryState;
    }
    Component.prototype.Load = function () {
        var _this = this;
        if (this.Content != null) {
            console.log('Not Update');
            return;
        }
        $.ajax({
            type: 'GET',
            url: this.Url,
            headers: {
                'x-pjax': true
            },
            success: function success(data) {
                _this.Content = data;
                $(_this.Container).html(_this.Content);
                history.pushState(_this.HistoryState, '', _this.Url);
            }
        });
    };
    return Component;
}();
var HistoryState = function () {
    function HistoryState(Page) {
        this.Page = Page;
    }
    return HistoryState;
}();