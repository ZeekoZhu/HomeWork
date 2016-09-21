var bgSpaFolders = [
    'ClassManage',
    'OrderManage'
];

module.exports = {
    port: 3000,
    files: ["./dist/**/*.{html,htm,css,js}"],
    server: {
        baseDir: './dist',
        routes: {
            '/res': './res',
            '/node_modules': './node_modules'
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
                        req.url = '/';
                    }
                }
                console.log(controller);
                return next();
            }
        }
    }
};
