require(['./Component.js'], function () {
    $().ready(function () {
        var searchComponent = new Component('/AirTicket/Search.html', $('.main-container')[0], new HistoryState('search'), ['./AirTicket/search.js']);
        searchComponent.Load();
    });
});
