## 設計

- Kicadで設計
- elecrowに発注
- 突貫設計なので...

## gitbookのビルド

- [gitbook-plugin-github](https://www.npmjs.com/package/gitbook-plugin-github)使用

```
cd document
npm i gitbook-cli -g
npm i gitbook-plugin-github -g
gitbook install
gitbook build . ../docs
```