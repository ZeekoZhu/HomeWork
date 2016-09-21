module.exports = function (bs) {
    var send = require('send');
    var bgSpaFolders = [
        'ClassManage',
        'OrderManage'
    ];

    return {
        port: 3000,
        files: ['./**/*.{html,htm,css,js}'],

        server: {
            baseDir: './src',
            routes: {
              '/res':'./res'  
            },
            middleware: {
                1: function (req, res, next) {
                    var isPjax = req.headers['x-pjax'];
                    if (isPjax === 'true') {
                        console.log('from pjax');
                        return next();
                    }
                    var path = req.url;
                    var controller = path.split('/')[1].toLowerCase();
                    var isPartOfSpa = false;
                    for (var i = 0; i < bgSpaFolders.length; i++) {
                        if (bgSpaFolders[i].toLowerCase() === controller) {
                            req.url = '/OrderManage/List.html';
                        }
                    }
                    return next();
                }
            }
        }
    }
}