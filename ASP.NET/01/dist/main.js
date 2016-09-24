'use strict';

require(['./Component.js'], function () {
    var mainContainer = $('.main-container')[0];
    var searchComponent = new Component('/AirTicket/Search.html', mainContainer, new HistoryState('search'), ['./AirTicket/search.js']);
    var submitComponent = new Component('/AirTicket/Submit.html', mainContainer, new HistoryState('submit'), ['']);
    var confirmComponent = new Component('./AirTicket/confirm.html', mainContainer, new HistoryState('confirm'), ['']);
    $().ready(function () {
        // searchComponent.Load();
        // confirmComponent.Load();
        submitComponent.Load();
    });
});