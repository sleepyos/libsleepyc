{ pkgs ? import <nixpkgs> { }
, lib ? pkgs.lib
, ...
}:

pkgs.mkShell {
  buildInputs = with pkgs; [
    clang

    meson
    ninja
  ];
}
