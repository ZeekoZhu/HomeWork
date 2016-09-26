## 运行环境
* Firefox 45 +
* Chrome / Chromuium 50 +

## 运行方法
1. 安装 nodejs 以及 npm
2. 安装 typescript 编译器
```
npm i -g typescript
```

2. 在根目录执行以安装依赖
```
npm install
```
3. 运行
```
gulp dev
```

## 切换页面的方法
在 main.ts Line 24 中通过修改 `begin` 的值来切换到不同页面

## 备注
还有确认订单的页面好难写，写不出来