FROM paperist/texlive-ja:latest

# latexmk is a Perl script, so Perl runtime is required.
# Also install poppler-utils for PDF text extraction
RUN apt-get update && \
    apt-get install -y --no-install-recommends perl poppler-utils && \
    rm -rf /var/lib/apt/lists/*

# 数学教材作成用のパッケージを追加
RUN tlmgr update --self && \
    tlmgr install physics pgf pgfplots tikz-cd

# Expose TeX Live binaries to non-login shells used by `sh -lc`.
RUN TEXBIN="$(find /usr/local/texlive -maxdepth 4 -type d -path '*/bin/*' | head -n 1)" && \
    ln -sf "${TEXBIN}"/* /usr/local/bin/