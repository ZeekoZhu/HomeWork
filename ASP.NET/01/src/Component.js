var Component = (function () {
    function Component(Url, Container, HistoryState, Scripts) {
        this.Url = Url;
        this.Container = Container;
        this.HistoryState = HistoryState;
        this.Scripts = Scripts;
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
            success: function (data) {
                _this.Content = data;
                $(_this.Container).html(_this.Content);
                history.pushState(_this.HistoryState, '', _this.Url);
                require(_this.Scripts);
            }
        });
    };
    return Component;
}());
var HistoryState = (function () {
    function HistoryState(Page) {
        this.Page = Page;
    }
    return HistoryState;
}());
