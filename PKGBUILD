# Maintainerl: wateir <contact@wateir.fr>

pkgname=VPgitT-git
pkgver=r20.4a405d6
pkgrel=1
pkgdesc="Very Personal GIT Tool"
arch=("any")
url="https://github.com/Wateir/VPgitT"
licence=('MIT')
provides=('VPgitT')
depends=("git" "fzf")
makedepends=("git")
source=("git+https://github.com/Wateir/VPgitT")
sha256sums=('SKIP')

pkgver() {
    cd "$srcdir/VPgitT"
    printf "r%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short=7 HEAD)"
}

package() {
  cd "$srcdir/VPgitT"
  make

  install -Dm755 "VPgitT" "$pkgdir/usr/bin/VPgitT"
}
