\setSpace\ {
    clean [-]
    set to 32 ++++++++++++++++++++++++++++++++
}

\spaceToZeroChar\ {
    add 16 ++++++++++++++++
}

\spaceToOneChar\ {
    add 17 +++++++++++++++++
}

\spaceToTwoChar\ {
    add 18 ++++++++++++++++++
}

\spaceToThreeChar\ {
    add 19 +++++++++++++++++++
}

\spaceToFourChar\ {
    add 20 ++++++++++++++++++++
}

\spaceToFiveChar\ {
    add 21 +++++++++++++++++++++
}

\spaceToSixChar\ {
    add 22 ++++++++++++++++++++++
}

\spaceToSevenChar\ {
    add 23 +++++++++++++++++++++++
}

\spaceToHeightChar\ {
    add 24 ++++++++++++++++++++++++
}

\spaceToNinceChar\ {
    add 25 +++++++++++++++++++++++++
}

\spaceToA\ {
    add 33 +++++++++++++++++++++++++++++++++
}

\spaceToB\ {
    ++++++++++++++++++++++++++++++++++
}

\spaceToC\ {
    +++++++++++++++++++++++++++++++++++
}

\spaceToD\ {
    ++++++++++++++++++++++++++++++++++++
}

\spaceToE\ {
    +++++++++++++++++++++++++++++++++++++
}

\spaceToF\ {
    ++++++++++++++++++++++++++++++++++++++
}

\spaceToG\ {
    +++++++++++++++++++++++++++++++++++++++
}

\spaceToH\ {
    ++++++++++++++++++++++++++++++++++++++++
}

\spaceToI\ {
    +++++++++++++++++++++++++++++++++++++++++
}

\spaceToJ\ {
    ++++++++++++++++++++++++++++++++++++++++++
}

\spaceToK\ {
    +++++++++++++++++++++++++++++++++++++++++++
}

\spaceToL\ {
    ++++++++++++++++++++++++++++++++++++++++++++
}

\spaceToM\ {
    +++++++++++++++++++++++++++++++++++++++++++++
}

\spaceToN\ {
    ++++++++++++++++++++++++++++++++++++++++++++++
}

\spaceToO\ {
    +++++++++++++++++++++++++++++++++++++++++++++++
}

\spaceToP\ {
    ++++++++++++++++++++++++++++++++++++++++++++++++
}

\spaceToQ\ {
    +++++++++++++++++++++++++++++++++++++++++++++++++
}

\spaceToR\ {
    ++++++++++++++++++++++++++++++++++++++++++++++++++
}

\spaceToS\ {
    +++++++++++++++++++++++++++++++++++++++++++++++++++
}

\spaceToT\ {
    ++++++++++++++++++++++++++++++++++++++++++++++++++++
}

\spaceToU\ {
    +++++++++++++++++++++++++++++++++++++++++++++++++++++
}

\spaceToV\ {
    ++++++++++++++++++++++++++++++++++++++++++++++++++++++
}

\spaceToW\ {
    +++++++++++++++++++++++++++++++++++++++++++++++++++++++
}

\spaceToX\ {
    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
}

\spaceToY\ {
    +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
}

\spaceToZ\ {
    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
}

\initializeText\ Need 1 argument "size" $ Need "size" plus 2 spaces $ Initialize "size" memory to space char {
    
    First step
    [->+>+<<]>->[-<<+>>]<
    
    Moving forward [
        clean >[-]>[-]<<
        remaining [->+<]>-
        copy total <<[->+>>+<<<]>>>[-<<<+>>>]
        <
    ]

    <-

    Going backwards
    [
        Cleaning previous <[-]>
        remaining [-<+>]
        /setSpace/
        <-
    ]

    /setSpace/
}