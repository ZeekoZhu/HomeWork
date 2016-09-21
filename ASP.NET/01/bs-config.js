var bgSpaFolders = [
    'AirTicket'
];

module.exports = {
    port: 3000,
    files: ["./dist/**/*.{html,htm,css,js}"],
    server: {
        logLevel: 'info',
        baseDir: './dist',
        routes: {
            '/res': './res',
            '/node_modules': './node_modules'
        },
        middleware: {
            1: function (req, res, next) {
                var ext = '';
                if (/\.(\w+)$/.exec(req.url) != null) {
                    ext = /\.(\w+)$/.exec(req.url)[1];
                }
                if (ext.toLowerCase() === 'html') {
                    var isPjax = req.headers['x-pjax'];
                    if (isPjax === 'true') {
                        console.log('from pjax');
                        return next();
                    }
                    var path = req.url;
                    console.log(path);
                    var controller = path.split('/')[1].toLowerCase();
                    var isPartOfSpa = false;
                    console.info(controller);
                    for (var i = 0; i < bgSpaFolders.length; i++) {
                        if (bgSpaFolders[i].toLowerCase() === controller) {
                            req.url = '/index.html';
                        }
                    }
                    console.log(req.url);
                }
                return next();

            }
        }
    }
};
