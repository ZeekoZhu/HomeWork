/// <reference path="./Component.ts" />

$().ready(() => {
    let searchComponent =
        new Component('/AirTicket/Search.html',
            $('.main-container')[0],
            new HistoryState('search'));
    searchComponent.Load();
});