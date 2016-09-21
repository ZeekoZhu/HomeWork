var gulp           = require('gulp');
var concat         = require('gulp-concat');
var rename         = require('gulp-rename');
var uglify         = require('gulp-uglify');
var eslint         = require('gulp-eslint');
var changed        = require('gulp-changed');
var cssmin         = require('gulp-clean-css');
var autoPrefix     = require('gulp-autoprefixer');
var mainBowerFiles = require('main-bower-files');
var flatten        = require('gulp-flatten');
var gulpFilter     = require('gulp-filter');
var exec           = require('child_process').exec;
var csslint        = require('gulp-csslint');

// Load plugins
var $ = require('gulp-load-plugins')();

var SRC      = './src/**/*.';
var JS_SRC   = SRC + 'js';
var HTML_SRC = SRC + 'html';
var CSS_SRC  = SRC + 'css';

var DEST     = './dist/';
var LIB_DEST = './dist/lib';

/**
 * js 检查
 */
gulp.task('jslint', function () {
    return gulp.src([JS_SRC])
        .pipe(eslint({
            configFile: './configs/.eslintrc.json',
            globals: [
                'jQuery',
                '$'
            ],
            envs: [
                'browser'
            ]
        }))
        .pipe(eslint.formatEach('compact', process.stderr));
});

/**
 * css 检查
 */
gulp.task('csslint', function () {
    return gulp.src([CSS_SRC])
        .pipe(csslint('./configs/csslintrc.json'))
        .pipe(csslint.formatter());
});


/**
 * 压缩 js 文件
 */
gulp.task('minify-js', function () {
    return gulp.src(JS_SRC)
        .pipe(changed(DEST))
        .pipe($.plumber())
        .pipe($.babel({
            presets: ['es2015']
        }))
        .pipe(gulp.dest(DEST))
        .pipe(uglify())
        .pipe(rename({ extname: '.min.js' }))
        .pipe(gulp.dest(DEST));
});

/**
 * minify css
 */
gulp.task('minify-css', function () {
    return gulp.src(CSS_SRC)
        .pipe(autoPrefix({
            browsers: ['> 1% in CN'],
            cascade: false
        }))
        .pipe(gulp.dest(DEST))
        .pipe(cssmin())
        .pipe(rename({ extname: '.min.css' }))
        .pipe(gulp.dest(DEST));
});


gulp.task('html', function () {
    return gulp.src(HTML_SRC)
        .pipe(gulp.dest(DEST));
});

/**
 * copy third party files to dist/lib
 */
gulp.task('copy-lib', function () {
    var jsFilter = gulpFilter(['**/*.js'], { restore: true });
    var cssFilter = gulpFilter('**/*.css', { restore: true });
    var fontFilter = gulpFilter(['**/*.eot', '**/*.woff', '**/*.svg', '**/*.ttf'], { restore: true });

    return gulp.src(mainBowerFiles())

        // grab vendor js files from bower_components, minify and push in /public
        .pipe(jsFilter)
        .pipe(gulp.dest(LIB_DEST + '/js/'))
        .pipe(jsFilter.restore)

        // grab vendor css files from bower_components, minify and push in /public
        .pipe(cssFilter)
        .pipe(gulp.dest(LIB_DEST + '/css'))
        .pipe(cssFilter.restore)

        // grab vendor font files from bower_components and push in /public
        .pipe(fontFilter)
        .pipe(flatten())
        .pipe(gulp.dest(LIB_DEST + '/fonts'));
});

/**
 * lite-server
 */
gulp.task('lite-server', function (cb) {
    exec('npm run lite', function (err, stdout, stderr) {
        console.log(stdout);
        console.log(stderr);
        cb(err);
    });
});

gulp.task('watch', function () {
    gulp.watch('./src/**/*.js', ['minify-js']);
    gulp.watch('./src/**/*.css', ['minify-css']);
    gulp.watch('./src/**/*.html', ['html']);
});

gulp.task('dev', ['watch', 'lite-server']);

/**
 * build files
 */
gulp.task('build', ['jslint', 'minify-js', 'minify-css', 'html']);
