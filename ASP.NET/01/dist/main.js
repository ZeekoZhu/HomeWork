'use strict';

/// <reference path="./Component.ts" />
$().ready(function () {
    var searchComponent = new Component('/AirTicket/Search.html', $('.main-container')[0], new HistoryState('search'));
    searchComponent.Load();
});