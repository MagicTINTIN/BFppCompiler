+-
\generateHelloWorld\ {
    #{hello.b}
    <<<<
}

\ifZeroIncrement\ {
    [*]+
}

\incrementToNextNonZero\ {
    +
    /ifZeroIncrement/
}

\largeClean\ {
    [-]-
    [>[-]<[->+<]>-]
    [-]-
    [[-<+>]<-]
}