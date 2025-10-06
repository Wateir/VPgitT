#Maintainerl: wateir <contact@wateir.fr>

pkgname=why3-git
pkgver=r16737.389fdf8
pkgrel=1
pkgdesc="Platform for deductive program verification"
arch=("x86_64")
url="https://gitlab.inria.fr/why3/why3"
licence=('GNU LGPL 2.1.')
provides=('why3')
depends=("ocaml" "lablgtk3" "ocaml-menhir" "emacs" "ocaml-zarith")
optdepends=(
	'coq: For use coq realizations'
	'cvc4: prover'
	'z3: prover'
	)
makedepends=("git" "ocaml-compiler-libs" "bash")
source=("git+https://gitlab.inria.fr/why3/why3")
md5sums=('SKIP')

pkgver() {
    cd "$srcdir/why3"
    printf "r%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short=7 HEAD)"
}

package() {

  cd "$srcdir/why3"	
	
  make
}
