#include "analysisLine_opponent.h"
#include "initialize.h"

int analysisLine_opponent(const int line[], int turn) {
    int opponentScore = 0, cntLeft = 0, cntRight = 0;
    for (; line[4 - cntLeft] == 3 - turn; cntLeft++);
    for (; line[6 + cntRight] == 3 - turn; cntRight++);
    switch (cntLeft) { // NOLINT(hicpp-multiway-paths-covered)
        case 4:
            if (line[0] == 0)
                opponentScore += chessType.LIAN5 - chessType.CHONG4; //011112
            else
                opponentScore += chessType.LIAN5; //211112
            break;
        case 3:
            if (line[1] == 0) {
                if (line[0] == 0) {
                    if (line[6] == 0)
                        opponentScore += chessType.HUO4 - chessType.MIAN3; //0011120
                    else if (line[6] == turn || line[6] == -1)
                        opponentScore += chessType.CHONG4 - chessType.MIAN3; //0011122
                } else if (line[0] == turn || line[0] == -1) {
                    if (line[6] == 0)
                        opponentScore += chessType.HUO4; //2011120
                    else if (line[6] == turn || line[6] == -1)
                        opponentScore += chessType.CHONG4; //2011122
                }
            } else if (line[1] == turn || line[1] == -1) {
                if (line[6] == 0)
                    opponentScore += chessType.CHONG4; //211120
            }
            break;
        case 2:
            if (line[2] == 0) {
                if (line[1] == 0) {
                    if (line[6] == 0) {
                        if (line[0] == 0)
                            opponentScore += chessType.HUO3 - chessType.MIAN2; //0001120
                        else if (line[0] == turn || line[0] == -1)
                            opponentScore += chessType.HUO3; //2001120
                    } else if (line[6] == turn || line[6] == -1) {
                        if (line[0] == 0)
                            opponentScore += chessType.HUO3 - chessType.MIAN2; //0001122
                        else if (line[0] == turn || line[0] == -1)
                            opponentScore += chessType.MIAN3; //2001122
                    }
                } else if (line[1] == 3 - turn) {
                    if (line[0] == turn || line[0] == -1)
                        opponentScore += chessType.CHONG4; //210112
                } else if (line[1] == turn || line[1] == -1) {
                    if (line[6] == 0) {
                        if (line[7] == 0)
                            opponentScore += chessType.HUO3; //2011200
                        else if (line[7] == turn || line[7] == -1)
                            opponentScore += chessType.MIAN3; //2011202
                    }
                }
            } else if (line[2] == turn || line[2] == -1) {
                if (line[6] == 0 && line[7] == 0)
                    opponentScore += chessType.MIAN3; //211200
            }
            break;
        case 1:
            if (line[3] == 0) {
                if (line[2] == 0) {
                    if (line[1] == 3 - turn) {
                        if (line[0] == 0)
                            opponentScore += chessType.MIAN3 - chessType.MIAN2; //010012
                        else
                            opponentScore += chessType.MIAN3; //210012
                    } else if (line[1] == turn || line[1] == -1) {
                        if (line[6] == 0) {
                            if (line[7] == 0)
                                opponentScore += chessType.HUO2; //2001200
                            else if (line[7] == turn || line[7] == -1)
                                opponentScore += chessType.MIAN2; //2001202
                        }
                    } else if (line[1] == 0) {
                        if (line[6] == 0)
                            opponentScore += chessType.HUO2; //000120
                        else if (line[6] == turn || line[6] == -1)
                            opponentScore += chessType.MIAN2; //000122
                    }
                } else if (line[2] == 3 - turn) {
                    if (line[1] == 0) {
                        if (line[6] == 0) {
                            if (line[0] == 0)
                                opponentScore += chessType.HUO3 - chessType.MIAN2; //0010120
                            else
                                opponentScore += chessType.HUO3; //2010120
                        } else if (line[6] == turn || line[6] == -1) {
                            if (line[0] == 0)
                                opponentScore += chessType.MIAN3 - chessType.MIAN2; //0010122
                            else
                                opponentScore += chessType.MIAN3; //2010122
                        }
                    } else if (line[1] == 3 - turn) {
                        if (line[0] == turn || line[0] == -1)
                            opponentScore += chessType.CHONG4; //211012
                    } else if (line[1] == turn || line[1] == -1) {
                        if (line[6] == 0)
                            opponentScore += chessType.MIAN3; //210120
                    }
                } else if (line[2] == turn || line[2] == -1) {
                    if (line[6] == 0 && line[7] == 0 && line[8] == 0)
                        opponentScore += chessType.HUO2; //2012000
                    else if (line[6] == 0 && line[7] == 0 && (line[8] == turn || line[8] == -1))
                        opponentScore += chessType.MIAN2; //2012002
                }
            } else if (line[3] == turn || line[3] == -1) {
                if (line[6] == 0 && line[7] == 0 && line[8] == 0)
                    opponentScore += chessType.MIAN2; //212000
            }
            break;
        case 0:
            if (line[4] == 0) {
                if (line[3] == 0) {
                    if (line[2] == 0) {
                        if (line[1] == 3 - turn)
                            opponentScore += chessType.MIAN2; //10002
                    } else if (line[2] == 3 - turn) {
                        if (line[1] == 0) {
                            if (line[6] == 0)
                                opponentScore += chessType.HUO2; //010020
                            else if (line[6] == turn || line[6] == -1)
                                opponentScore += chessType.MIAN2; //010022
                        } else if (line[1] == 3 - turn) {
                            if (line[0] == 0)
                                opponentScore += chessType.MIAN3 - chessType.MIAN2; //011002
                            else
                                opponentScore += chessType.MIAN3; //211002
                        } else if ((line[1] == turn || line[1] == -1) && line[6] == 0)
                            opponentScore += chessType.MIAN2; //210020
                    }
                } else if (line[3] == 3 - turn) {
                    if (line[2] == 0) {
                        if (line[1] == 0) {
                            if (line[6] == 0)
                                opponentScore += chessType.HUO2; //001020
                            else if (line[6] == turn || line[6] == -1)
                                opponentScore += chessType.MIAN2; //001022
                        } else if (line[1] == 3 - turn) {
                            if (line[0] == turn || line[0] == -1)
                                opponentScore += chessType.MIAN3; //210102
                            else if (line[0] == 0)
                                opponentScore += chessType.MIAN3 - chessType.MIAN2; //010102
                        } else if (line[1] == turn || line[1] == -1) {
                            if (line[6] == 0) {
                                if (line[7] == 0)
                                    opponentScore += chessType.HUO2; //2010200
                                else if (line[7] == turn || line[7] == -1)
                                    opponentScore += chessType.MIAN2; //2010202
                            }
                        }
                    } else if (line[2] == 3 - turn) {
                        if (line[1] == 0) {
                            if (line[0] == 0) {
                                if (line[6] == 0)
                                    opponentScore += chessType.HUO3 - chessType.MIAN2; //0011020
                                else if (line[6] == turn || line[6] == -1) {
                                    opponentScore += chessType.MIAN3 - chessType.MIAN2; //0011022
                                }
                            } else if (line[0] == turn || line[0] == -1) {
                                if (line[6] == 0)
                                    opponentScore += chessType.HUO3; //2011020
                                else if (line[6] == turn || line[6] == -1)
                                    opponentScore += chessType.MIAN3; //2011022
                            }
                        } else if (line[1] == 3 - turn) {
                            if (line[0] == turn || line[0] == -1)
                                opponentScore += chessType.CHONG4; //211102
                        } else if (line[1] == turn || line[1] == -1) {
                            if (line[6] == 0)
                                opponentScore += chessType.MIAN3; //211020
                        }
                    } else if (line[2] == turn || line[2] == -1) {
                        if (line[6] == 0 && line[7] == 0)
                            opponentScore += chessType.MIAN2; //210200
                    }
                }
            }
            break;
    }
    switch (cntRight) { // NOLINT(hicpp-multiway-paths-covered)
        case 4:
            if (line[10] == 0)
                opponentScore += chessType.LIAN5 - chessType.CHONG4; //211110
            else
                opponentScore += chessType.LIAN5; //211112
            break;
        case 3:
            if (line[9] == 0) {
                if (line[10] == 0) {
                    if (line[4] == 0)
                        opponentScore += chessType.HUO4 - chessType.MIAN3; //0211100
                    else if (line[4] == turn || line[4] == -1)
                        opponentScore += chessType.CHONG4 - chessType.MIAN3; //2211100
                } else if (line[10] == turn || line[10] == -1) {
                    if (line[4] == 0)
                        opponentScore += chessType.HUO4; //0211102
                    else if (line[4] == turn || line[4] == -1)
                        opponentScore += chessType.CHONG4; //2211102
                }
            } else if (line[9] == turn || line[9] == -1) {
                if (line[4] == 0)
                    opponentScore += chessType.CHONG4; //211120
            }
            break;
        case 2:
            if (line[8] == 0) {
                if (line[9] == 0) {
                    if (line[4] == 0) {
                        if (line[10] == 0)
                            opponentScore += chessType.HUO3 - chessType.MIAN2; //0211000
                        else if (line[10] == turn || line[10] == -1)
                            opponentScore += chessType.HUO3; //0211002
                    } else if (line[4] == turn || line[4] == -1) {
                        if (line[10] == 0)
                            opponentScore += chessType.HUO3 - chessType.MIAN2; //2211000
                        else if (line[10] == turn || line[10] == -1)
                            opponentScore += chessType.MIAN3; //2211002
                    }
                } else if (line[9] == 3 - turn) {
                    if (line[10] == turn || line[10] == -1)
                        opponentScore += chessType.CHONG4; //211012
                } else if (line[9] == turn || line[9] == -1) {
                    if (line[4] == 0) {
                        if (line[3] == 0)
                            opponentScore += chessType.HUO3; //0021102
                        else if (line[3] == turn || line[3] == -1)
                            opponentScore += chessType.MIAN3; //2021102
                    }
                }
            } else if (line[8] == turn || line[8] == -1) {
                if (line[4] == 0 && line[3] == 0)
                    opponentScore += chessType.MIAN3; //002112
            }
            break;
        case 1:
            if (line[7] == 0) {
                if (line[8] == 0) {
                    if (line[9] == 3 - turn) {
                        if (line[10] == 0)
                            opponentScore += chessType.MIAN3 - chessType.MIAN2; //210010
                        else
                            opponentScore += chessType.MIAN3; //210012
                    } else if (line[9] == turn || line[9] == -1) {
                        if (line[4] == 0) {
                            if (line[3] == 0)
                                opponentScore += chessType.HUO2; //0021002
                            else if (line[3] == turn || line[3] == -1)
                                opponentScore += chessType.MIAN2; //2021002
                        }
                    } else if (line[9] == 0) {
                        if (line[4] == 0)
                            opponentScore += chessType.HUO2; //021000
                        else if (line[4] == turn || line[4] == -1)
                            opponentScore += chessType.MIAN2; //221000
                    }
                } else if (line[8] == 3 - turn) {
                    if (line[9] == 0) {
                        if (line[4] == 0) {
                            if (line[10] == 0)
                                opponentScore += chessType.HUO3 - chessType.MIAN2; //0210100
                            else
                                opponentScore += chessType.HUO3; //0210102
                        } else if (line[4] == turn || line[4] == -1) {
                            if (line[10] == 0)
                                opponentScore += chessType.MIAN3 - chessType.MIAN2; //2210100
                            else
                                opponentScore += chessType.MIAN3; //2210102
                        }
                    } else if (line[9] == 3 - turn) {
                        if (line[10] == turn || line[10] == -1)
                            opponentScore += chessType.CHONG4; //210112
                    } else if (line[9] == turn || line[9] == -1) {
                        if (line[4] == 0)
                            opponentScore += chessType.MIAN3; //021012
                    }
                } else if (line[8] == turn || line[8] == -1) {
                    if (line[4] == 0 && line[3] == 0 && line[2] == 0)
                        opponentScore += chessType.HUO2; //0002102
                    else if (line[4] == 0 && line[3] == 0 && (line[2] == turn || line[2] == -1))
                        opponentScore += chessType.MIAN2; //2002102
                }
            } else if (line[7] == turn || line[7] == -1) {
                if (line[4] == 0 && line[3] == 0 && line[2] == 0)
                    opponentScore += chessType.MIAN2; //000212
            }
            break;
        case 0:
            if (line[6] == 0) {
                if (line[7] == 0) {
                    if (line[8] == 0) {
                        if (line[9] == 3 - turn)
                            opponentScore += chessType.MIAN2; //20001
                    } else if (line[8] == 3 - turn) {
                        if (line[9] == 0) {
                            if (line[4] == 0)
                                opponentScore += chessType.HUO2; //020010
                            else if (line[4] == turn || line[4] == -1)
                                opponentScore += chessType.MIAN2; //220010
                        } else if (line[9] == 3 - turn) {
                            if (line[10] == 0)
                                opponentScore += chessType.MIAN3 - chessType.MIAN2; //200110
                            else
                                opponentScore += chessType.MIAN3; //200112
                        } else if ((line[9] == turn || line[9] == -1) && line[4] == 0)
                            opponentScore += chessType.MIAN2; //020012
                    }
                } else if (line[7] == 3 - turn) {
                    if (line[8] == 0) {
                        if (line[9] == 0) {
                            if (line[4] == 0)
                                opponentScore += chessType.HUO2; //020100
                            else if (line[4] == turn || line[4] == -1)
                                opponentScore += chessType.MIAN2; //220100
                        } else if (line[9] == 3 - turn) {
                            if (line[10] == turn || line[10] == -1)
                                opponentScore += chessType.MIAN3; //201012
                            else if (line[10] == 0)
                                opponentScore += chessType.MIAN3 - chessType.MIAN2; //201010
                        } else if (line[9] == turn || line[9] == -1) {
                            if (line[4] == 0) {
                                if (line[3] == 0)
                                    opponentScore += chessType.HUO2; //0020102
                                else if (line[3] == turn || line[3] == -1)
                                    opponentScore += chessType.MIAN2; //2020102
                            }
                        }
                    } else if (line[8] == 3 - turn) {
                        if (line[9] == 0) {
                            if (line[10] == 0) {
                                if (line[4] == 0)
                                    opponentScore += chessType.HUO3 - chessType.MIAN2; //0201100
                                else if (line[4] == turn || line[4] == -1) {
                                    opponentScore += chessType.MIAN3 - chessType.MIAN2; //2201100
                                }
                            } else if (line[10] == turn || line[10] == -1) {
                                if (line[4] == 0)
                                    opponentScore += chessType.HUO3; //0201102
                                else if (line[4] == turn || line[4] == -1)
                                    opponentScore += chessType.MIAN3; //2201102
                            }
                        } else if (line[9] == 3 - turn) {
                            if (line[10] == turn || line[10] == -1)
                                opponentScore += chessType.CHONG4; //201112
                        } else if (line[9] == turn || line[9] == -1) {
                            if (line[4] == 0)
                                opponentScore += chessType.MIAN3; //020112
                        }
                    } else if (line[8] == turn || line[8] == -1) {
                        if (line[4] == 0 && line[3] == 0)
                            opponentScore += chessType.MIAN2; //002012
                    }
                }
            }
            break;
    }
    if (cntLeft == 1 && cntRight == 3) {
        if (line[9] == 0 && line[10] == 0)
            return opponentScore + chessType.LIAN5 - chessType.MIAN3; //1211100
        else
            return opponentScore + chessType.LIAN5; //12111
    }
    if (cntLeft == 3 && cntRight == 1) {
        if (line[1] == 0 && line[0] == 0)
            return opponentScore + chessType.LIAN5 - chessType.MIAN3; //0011121
        else
            return opponentScore + chessType.LIAN5; //11121
    }
    if (cntLeft == 2 && cntRight == 2) {
        if (line[2] == 0 && line[1] == 0 && line[0] == 0 && line[8] == 0 && line[9] == 0 && line[10] == 0)
            return opponentScore + chessType.LIAN5 - 2 * chessType.MIAN2; //00011211000
        else if ((line[2] == 0 && line[1] == 0 && line[0] == 0) || (line[8] == 0 && line[9] == 0 && line[10] == 0))
            return opponentScore + chessType.LIAN5 - chessType.MIAN2; //00011211|11211000
        else
            return opponentScore + chessType.LIAN5; //11211
    }
    if (cntLeft == 1 && cntRight == 2) {
        if (line[3] == 0 && line[8] == 0) {
            if (line[9] == 0 && line[10] == 0)
                return opponentScore + chessType.HUO4 - chessType.MIAN2; //01211000
            else
                return opponentScore + chessType.HUO4; //012110
        } else if (line[8] == 0) {
            if (line[9] == 0 && line[10] == 0)
                return opponentScore + chessType.CHONG4 - chessType.MIAN2; //21211000
            else
                return opponentScore + chessType.CHONG4; //212110
        } else if (line[3] == 0)
            return opponentScore + chessType.CHONG4; //012112
    }
    if (cntLeft == 2 && cntRight == 1) {
        if (line[7] == 0 && line[2] == 0) {
            if (line[1] == 0 && line[0] == 0)
                return opponentScore + chessType.HUO4 - chessType.MIAN2; //00011210
            else
                return opponentScore + chessType.HUO4; //011210
        } else if (line[2] == 0) {
            if (line[1] == 0 && line[0] == 0)
                return opponentScore + chessType.CHONG4 - chessType.MIAN2; //00011212
            else
                return opponentScore + chessType.CHONG4; //011212
        } else if (line[7] == 0)
            return opponentScore + chessType.CHONG4; //211210
    }
    if (cntLeft == 0 && cntRight == 2 && line[4] == 0) {
        if (line[3] == 3 - turn) {
            if (line[8] == 0 && line[9] == 0 && line[10] == 0)
                return opponentScore + chessType.CHONG4 - chessType.MIAN2; //10211000
            else
                return opponentScore + chessType.CHONG4; //10211
        }
    }
    if (cntLeft == 2 && cntRight == 0 && line[6] == 0) {
        if (line[7] == 3 - turn) {
            if (line[2] == 0 && line[1] == 0 && line[0] == 0)
                return opponentScore + chessType.CHONG4 - chessType.MIAN2; //00011201
            else
                return opponentScore + chessType.CHONG4; //11201
        }
    }
    if (cntLeft == 1 && cntRight == 1) {
        if ((line[3] == turn || line[3] == -1) && line[7] == 0 && line[8] == 0)
            return opponentScore + chessType.MIAN3; //212100
        if ((line[7] == turn || line[7] == -1) && line[3] == 0 && line[2] == 0)
            return opponentScore + chessType.MIAN3; //001212
        if (line[3] == 0 && line[2] == 3 - turn && line[7] == 0 && line[8] == 3 - turn) {
            if (line[1] == 0 && line[0] == 0 && line[9] == 0 && line[10] == 0)
                return opponentScore + 2 * chessType.CHONG4 - 2 * chessType.MIAN2; //00101210100
            else if ((line[1] == 0 && line[0] == 0) || (line[9] == 0 && line[10] == 0))
                return opponentScore + 2 * chessType.CHONG4 - chessType.MIAN2; //001012101||101210100
            else
                return opponentScore + 2 * chessType.CHONG4; //1012101
        }
        if (line[3] == 0 && line[2] == 3 - turn) {
            if (line[1] == 0 && line[0] == 0)
                return opponentScore + chessType.CHONG4 - chessType.MIAN2; //0010121
            else
                return opponentScore + chessType.CHONG4; //10121
        }
        if (line[7] == 0 && line[8] == 3 - turn) {
            if (line[9] == 0 && line[10] == 0)
                return opponentScore + chessType.CHONG4 - chessType.MIAN2; //1210100
            else
                return opponentScore + chessType.CHONG4; //12101
        }
        if (line[3] == 0 && line[7] == 0) {
            if ((line[2] == turn || line[2] == -1) && (line[8] == turn || line[8] == -1))
                return opponentScore + chessType.MIAN3; //2012102
            else if (((line[2] == turn || line[2] == -1) && line[8] == 0) || ((line[8] == turn || line[8] == -1) && line[2] == 0) || (line[2] == 0 && line[8] == 0))
                return opponentScore + chessType.HUO3; //2012100|0012102|0012100
        }
    }
    if (cntLeft == 0 && cntRight == 1 && line[4] == 0) {
        if (line[3] == 0 && line[2] == 3 - turn)
            return opponentScore + chessType.MIAN3; //10021
        if (line[3] == 3 - turn) {
            if (line[2] == 0 && line[7] == 0)
                return opponentScore + chessType.HUO3; //010210
            else if (line[2] == 3 - turn)
                return opponentScore + chessType.CHONG4; //11021
            else if (((line[2] == turn || line[2] == -1) && line[7] == 0) || (line[2] == 0 && (line[7] == turn || line[7] == -1)))
                return opponentScore + chessType.MIAN3; //210210|010212
        }
    }
    if (cntLeft == 1 && cntRight == 0 && line[6] == 0) {
        if (line[7] == 0 && line[8] == 3 - turn)
            return opponentScore + chessType.MIAN3; //12001
        if (line[7] == 3 - turn) {
            if (line[8] == 0 && line[3] == 0)
                return opponentScore + chessType.HUO3; //012010
            else if (line[8] == 3 - turn)
                return opponentScore + chessType.CHONG4; //12011
            else if (((line[8] == turn || line[8] == -1) && line[3] == 0) || (line[8] == 0 && (line[3] == turn || line[3] == -1)))
                return opponentScore + chessType.MIAN3; //012012|212010
        }
    }
    if (cntLeft == 0 && cntRight == 0 && line[4] == 0 && line[6] == 0) {
        if (line[3] == 3 - turn && line[7] == 3 - turn)
            return opponentScore + chessType.MIAN3; //10201
    }
    return opponentScore;
}