// プリント共通スクリプト（繰数・解答・穴埋め）
//
// HTML の中の紙（.sheet）は data-role で種類を分ける。
//   data-role="q"   … 問題（繰数・穴埋め）
//   data-role="ans" … 解答
// 開くときの URL で、どの紙を表示するかが決まる。
//   （何もなし） … 問題
//   ?left        … 問題の左段を右段に複製した Left版
//   ?ans         … 解答
(function () {
  const params = new URLSearchParams(location.search);
  const mode = params.has("ans") ? "ans" : params.has("left") ? "left" : "q";
  const role = mode === "ans" ? "ans" : "q";

  const sheets = [...document.querySelectorAll(".sheet")];
  sheets.forEach((s) => s.classList.toggle("hidden", (s.dataset.role || "q") !== role));
  const visible = sheets.filter((s) => !s.classList.contains("hidden"));

  // Left版：問題の1枚目の左段を右段に複製
  if (mode === "left") {
    const [left, right] = visible[0].querySelectorAll(":scope > .col");
    right.innerHTML = left.innerHTML;
  }

  // 節番号（Left版は左右の段とも 1 から）
  let n = 0;
  visible.forEach((s) => {
    s.querySelectorAll(":scope > .col").forEach((col) => {
      if (mode === "left") n = 0;
      col.querySelectorAll("section > h2").forEach((h) => {
        if (h.dataset.nonum !== undefined) return;
        const num = document.createElement("span");
        num.className = "num";
        num.textContent = String(++n);
        h.prepend(num);
      });
    });
  });

  renderMathInElement(document.body, {
    delimiters: [
      { left: "$$", right: "$$", display: true },
      { left: "\\[", right: "\\]", display: true },
      { left: "$", right: "$", display: false },
    ],
    throwOnError: false,
  });

  // はみ出しチェック：段の中身が紙に収まっていなければ赤枠を付ける
  document.fonts.ready.then(() => {
    visible.forEach((s) =>
      s.querySelectorAll(":scope > .col").forEach((col) => {
        if (col.scrollHeight > col.clientHeight + 1 || col.scrollWidth > col.clientWidth + 1)
          col.classList.add("overflow");
      })
    );
  });
})();
