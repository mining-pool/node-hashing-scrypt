{
    "targets": [
        {
            "target_name": "hashing",
            "sources": [
                "hashing.cpp",
                "scrypt.c",
            ],
            "include_dirs": [
                "crypto",
            ],
            "cflags_cc": [
                "-std=c++0x"
            ],
        }
    ]
}
