

require(['./Component.js'], () => {
    let mainContainer = $('.main-container')[0];
    let searchComponent = new Component(
        '/AirTicket/Search.html',
        mainContainer,
        new HistoryState('search'),
        ['./AirTicket/search.js']
    );

    let submitComponent = new Component(
        '/AirTicket/Submit.html',
        mainContainer,
        new HistoryState('submit'),
        ['']
    );
    let confirmComponent = new Component(
        './AirTicket/confirm.html',
        mainContainer,
        new HistoryState('confirm'),
        ['']
    );
    $().ready(() => {
        let begin = 1;
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
