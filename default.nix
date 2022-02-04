{ stdenv }:

stdenv.mkDerivation {
  name = "libforza-0.1";

  src = ./.;

  installPhase = ''
    mkdir -p $out/lib $out/include

    cp lib/libforza.a $out/lib
    cp include/forza.h $out/include
  '';
}