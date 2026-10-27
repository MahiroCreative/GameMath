// テキスト共通スクリプト
// ・節（h2）と小節（h3）に番号を振る（data-nonum を付けた見出しは除く）
// ・KaTeX で数式を描画する
// ・本文の幅からはみ出した図や数式に赤枠を付ける
(function () {
  let s = 0, ss = 0;
  document.querySelectorAll("main h2, main h3").forEach((h) => {
    if (h.dataset.nonum !== undefined) return;
    const num = document.createElement("span");
    num.className = "num";
    if (h.tagName === "H2") { s++; ss = 0; num.textContent = String(s); }
    else { ss++; num.textContent = `${s}.${ss}`; }
    h.prepend(num);
  });

  renderMathInElement(document.body, {
    delimiters: [
      { left: "$$", right: "$$", display: true },
      { left: "\\[", right: "\\]", display: true },
      { left: "$", right: "$", display: false },
    ],
    throwOnError: false,
  });

  document.fonts.ready.then(() => {
    const main = document.querySelector("main");
    const limit = main.getBoundingClientRect().right + 1;
    main.querySelectorAll(".fig, .formula, .katex-display, table").forEach((el) => {
      if (el.getBoundingClientRect().right > limit || el.scrollWidth > el.clientWidth + 1)
        el.classList.add("overflow");
    });
  });
})();
