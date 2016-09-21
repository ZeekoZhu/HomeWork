module.exports = {
    port: 3000,
    files: ["./dist/**/*.{html,htm,css,js}"],
    server: {
        baseDir: './dist',
        routes: {
            '/res':'./res'
        },
        middleware: {
        }
    }
};
