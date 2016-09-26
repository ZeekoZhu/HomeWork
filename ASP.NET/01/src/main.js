require(['./Component.js'], function () {
    var mainContainer = $('.main-container')[0];
    var searchComponent = new Component('/AirTicket/Search.html', mainContainer, new HistoryState('search'), ['./AirTicket/search.js']);
    var submitComponent = new Component('/AirTicket/Submit.html', mainContainer, new HistoryState('submit'), ['']);
    var confirmComponent = new Component('./AirTicket/confirm.html', mainContainer, new HistoryState('confirm'), ['']);
    $().ready(function () {
        var begin = 1;
        switch (begin) {
            case 1:
                searchComponent.Load();
                break;
            case 2:
                searchComponent.Load();
                break;
            case 3:
                confirmComponent.Load();
                break;
            default:
                break;
        }
    });
});
