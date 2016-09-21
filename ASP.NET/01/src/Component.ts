class Component {
    public Content: string;

    public constructor(
        public Url: string,
        public Container: Element,
        public HistoryState: HistoryState) {
    }

    Load() {
        let _this = this;
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
            }
        });
    }
}

class HistoryState {
    public constructor(
        public Page: string
    ) { }
}