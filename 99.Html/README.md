# 99.Html の作り方（HTML教材の共通ルール）

2026-10-27 に `99.LatexDocker/*.tex`（2026-10-30 に `old/LatexDocker/` へ移動）をすべてこのフォルダの HTML に変換した。そのとき変換作業用に使ったルールをもとにしている。

- 共通ファイル: `print.css` / `print.js`（プリント）、`text.css` / `text.js`（テキスト）、`build.ps1`（PDF化）
- 変換時は「内容を1文字も変えない」方針だったため、元教材の誤りもそのまま残っている（リポジトリ直下の HANDOFF.md 参照）。
- 変換時は共通ファイルを編集せず、足りないスタイルを各HTMLの `<style>` に追記した。そのため各HTMLに重複したスタイルがある（共通化は今後の課題）。
- LaTeX特有の全角スペース「　」による字下げは不要（CSSで処理）。

## 共通
- 数式は KaTeX。`$…$`（インライン）、`$$…$$`（ディスプレイ）。LaTeXの数式はほぼそのまま書ける。`align*` は `$$\begin{aligned}…\end{aligned}$$`。
- 数式の中に日本語を入れない（`\text{ の大きさ }` は数式の外のHTMLテキストにする）。
- HTMLの中の `<` `>` `&` は数式内でも `\lt` `\gt` を使うか `&lt;` にする（`&` は aligned/pmatrix の区切りとしてそのまま書いてよい）。
- 図（TikZ / pgfplots）は**インラインSVG**で描き直す。数式ラベルは SVG の <text> ではなく、`<span class="lbl" style="left:X%;top:Y%">$…$</span>` を figure の中に置く（指定点を中心に配置。X,Y は viewBox の幅・高さに対する割合）。普通の日本語ラベルも同じく lbl でよい。
  ```html
  <figure class="fig" style="width:55%">
    <svg viewBox="0 0 400 300">…</svg>
    <span class="lbl" style="left:40%;top:20%">$\vec{a}$</span>
  </figure>
  ```
  - SVG は y 軸が下向きなので座標変換に注意。座標計算が必要なら PowerShell で計算してよい（node/python は無い）。
  - 線の色は元の図に合わせる（blue→#0645ad 程度、red→#c00、gray→#888 など）。矢印は <marker> で。
  - 元のTikZ図と形・ラベル位置が同じになるように。グラフ（pgfplots）は関数の点を十分細かく計算して polyline/path で描く。
- 文字色クラス: .red .blue .green .gray

## プリント（繰数・解答・穴埋め）：B4横2段。print.css / print.js を使う
雛形（すでに完成している例）: `99.Html/繰数5_2次元ベクトル.html` を必ず読んで構造を真似ること。
```html
<!doctype html>
<html lang="ja">
<head>
<meta charset="utf-8">
<title>繰数1 数学基礎</title>
<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/katex@0.16.11/dist/katex.min.css">
<script defer src="https://cdn.jsdelivr.net/npm/katex@0.16.11/dist/katex.min.js"></script>
<script defer src="https://cdn.jsdelivr.net/npm/katex@0.16.11/dist/contrib/auto-render.min.js"></script>
<script defer src="print.js"></script>
<link rel="stylesheet" href="print.css">
</head>
<body>
<div class="sheet" data-role="q">  … 問題（LaTeX の \newpage の前が左段 .col、後が右段 .col）
<div class="sheet packed" data-role="ans"> … 解答（必要な枚数だけ）
</body></html>
```
- 1枚の紙 = `.sheet`。中に `.col` を2つ（左段・右段）。
- 節 = `<section><h2>節名</h2><p class="lead">指示文</p> … </section>`。節番号は print.js が自動で振るので書かない。
- 問題リスト: `<ol class="q"><li>…</li></ol>`（番号自動）。行間 `\\[1em]` 程度なら `ol.q.wide`。
- 計算表（`式 &= & 式 &= &` を横に並べる形）: `<div class="calc" style="--cols:5"><span>$5+8=$</span>…</div>`（左から右、上から下の順。元と同じ並び順になるよう注意）。
- `data-role="q"` の紙 … 通常（URLそのまま）で表示。`?left` で左段を右段に複製した Left版になる（自動）。
- `data-role="ans"` の紙 … `?ans` で表示。元の解答 .tex は「1節 = 1段」（節ごとに \newpage）なので、`.sheet.packed` の各 `.col` に解答の節を1つずつ入れる（6節なら紙3枚）。節見出しは元と同じ「○○ 解答」。
- 解答の小見出し（考え方・図説・途中式 など）は `<p class="label">考え方</p>`。答え一覧は `ol.q.tight`（または `.calc.tight`）。
- 図と文章を横並びにするときは `<div class="row">…</div>`。
- 穴埋めの空欄 `\blank{2cm}` → `<span class="blank" style="--w:2cm"></span>`。
- 紙からはみ出した段は PDF 上で赤い点線枠＋「はみ出し」表示になる。**はみ出しがゼロになるまで直すこと**（図を小さくする等。内容は削らない）。

## テキスト（教科書）：画面で読む用、印刷するとA4縦。text.css / text.js を使う
```html
<!doctype html>
<html lang="ja">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>2次元ベクトル</title>
<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/katex@0.16.11/dist/katex.min.css">
<script defer src="https://cdn.jsdelivr.net/npm/katex@0.16.11/dist/katex.min.js"></script>
<script defer src="https://cdn.jsdelivr.net/npm/katex@0.16.11/dist/contrib/auto-render.min.js"></script>
<script defer src="text.js"></script>
<link rel="stylesheet" href="text.css">
</head>
<body>
<main>
<h1>タイトル</h1>
<h2>節</h2>  <h3>小節</h3>   … 番号は text.js が自動で振る（元に番号が無い見出しは data-nonum）
</main>
</body></html>
```
- `\formula{…}` → `<div class="formula">$\displaystyle …$</div>`
- 囲み（考え方・補足など独自マクロ）→ `<div class="box"><p class="box-title">考え方</p>…</div>`
- 確認問題（multicols+enumerate）→ `<ol class="exercise">`
- 図は `.fig`（上記）。幅は % で指定（スマホでは自動で100%）。
- `\newpage` → `<hr class="pagebreak">`（印刷時の改ページ。画面では点線）。
- 表 → 普通の <table>。

## ビルドと確認（必須）
- PowerShell で `& "C:\Users\teacherM\Desktop\GitHub\GameMath\99.Html\build.ps1" ファイル名.html` を実行すると `99.Html/pdf/` にPDFができる（繰数は 通常/Left/ans の3つ、それ以外は1つ）。1ファイル十数秒かかる。
- できたPDFを Read ツールで開き、**元の LaTeX 版 PDF（old/LatexDocker/同名.pdf、解答は ans_….pdf）と見比べて**、次を確認する:
  1. 内容の抜け・重複がない（節数・問題数・数値を突き合わせる）
  2. 数式がすべて正しく描画されている（KaTeX のエラーは赤字で出る）
  3. 図の形・ラベル位置が元と同じで、ラベルが線に重なっていない
  4. 「はみ出し」表示がない
- 問題があれば直して再ビルドし、問題がなくなるまで繰り返す。

## 注意（Windows PowerShell 5.1）
- `.ps1` は **BOM付き UTF-8** で保存する。BOMなしだと日本語が化けて動かない。
- 座標計算などのスクリプトで関数名 `R` は使わない（既存のエイリアスと衝突する）。
- この環境では PDF をページ指定で開けない（pdftoppm が無い）。ページ数の多いテキストは、Edge の `--screenshot` でブラウザ表示を撮って確認する。
