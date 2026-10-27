# HTML教材を Edge で PDF に変換する（出力先：pdf フォルダ）
# 使い方：
#   .\build.ps1                          … このフォルダの .html をすべて変換
#   .\build.ps1 繰数5_2次元ベクトル.html  … 指定したファイルだけ変換
#
# 出力されるPDF
#   繰数○○.html   → 繰数○○.pdf / 繰数○○Left.pdf / ans_繰数○○.pdf（解答があれば）
#   それ以外       → ○○.pdf

param([Parameter(ValueFromRemainingArguments = $true)][string[]]$Files)

$edge = "${env:ProgramFiles(x86)}\Microsoft\Edge\Application\msedge.exe"
$here = $PSScriptRoot
$outDir = Join-Path $here "pdf"
New-Item -ItemType Directory -Force $outDir | Out-Null

if (-not $Files) { $Files = Get-ChildItem $here -Filter *.html | ForEach-Object Name }

function Convert-ToPdf($html, $query, $pdf) {
  $url = ([System.Uri](Join-Path $here $html)).AbsoluteUri + $query
  # 同時に複数ビルドしても衝突しないよう、毎回別の一時プロファイルを使う
  $profile = Join-Path $env:TEMP ("edge-pdf-" + [guid]::NewGuid())
  & $edge --headless --disable-gpu --no-pdf-header-footer "--user-data-dir=$profile" `
    --virtual-time-budget=15000 --run-all-compositor-stages-before-draw `
    "--print-to-pdf=$pdf" $url 2>$null | Out-Null
  Remove-Item -Recurse -Force $profile -ErrorAction SilentlyContinue
  Write-Host "  -> $(Split-Path $pdf -Leaf)"
}

foreach ($f in $Files) {
  $f = Split-Path $f -Leaf
  $name = [System.IO.Path]::GetFileNameWithoutExtension($f)
  Write-Host $f
  Convert-ToPdf $f "" (Join-Path $outDir "$name.pdf")
  if ($name -like "繰数*") {
    Convert-ToPdf $f "?left" (Join-Path $outDir "${name}Left.pdf")
    if (Select-String -Path (Join-Path $here $f) -Pattern 'data-role="ans"' -Quiet) {
      Convert-ToPdf $f "?ans" (Join-Path $outDir "ans_$name.pdf")
    }
  }
}
