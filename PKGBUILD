# Maintainerl: wateir <contact@wateir.fr>

pkgname=VPgitT-git
pkgver=r24.3b2057c
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

  if [ -e "$pkgdir/usr/bin/VPgitT" ]; then
      rm "$pkgdir/usr/bin/VPgitT"
  fi

  install -Dm755 "prog" "$pkgdir/usr/bin/VPgitT"
}
