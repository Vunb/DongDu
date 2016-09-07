{
    "targets": [
        {
            "target_name": "dongdu",
            "sources": [
                "dongdu.cc",
                "DicMap.cpp",
                "Feats.cpp",
                "FeaturesSelection.cpp",
                "Machine.cpp",
                "StrMap.cpp",
                "SylMap.cpp",
                "liblinear/linear.cpp",
                "liblinear/tron.cpp",
                "liblinear/tron.cpp",
                "liblinear/blas/daxpy.c",
                "liblinear/blas/ddot.c",
                "liblinear/blas/dnrm2.c",
                "liblinear/blas/dscal.c",
            ],
            "include_dirs": [
                "<!(node -e \"require('nan')\")",
                "liblinear"
            ]
        }
    ]
}