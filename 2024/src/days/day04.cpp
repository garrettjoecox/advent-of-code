#include <iostream>
#include <cassert>
#include <regex>
#include <map>
#include <sstream>
#include <string>

static std::string exampleInput = R""""(
MMMSXXMASM
MSAMXMSMSA
AMXSXMAAMM
MSAMASMSMX
XMASAMXAMM
XXAMMXXAMA
SMSMSASXSS
SAXAMASAAA
MAMMMXMMMM
MXMXAXMASX
)"""";

static std::string puzzleInput = R""""(
SSSMXMMSMMXXXSMXMASXSAXXMSXSMSXMMSSMMMSMAMXMASASXSXMMSXXXMAXSMSXMAMSAMXMSMAMSAMAMMXSAMXMMSAMMMMSMMMSMMXMMSSMMXSMAMMAAMAMXSSXXXAMXXXSASMSSSSS
MAASXMASAMXMXMMMXMMMSSMAXSAMXSAXMASAAAXMAAMMAAASMSAMSMAMSMMMXXXAMMMXMXMXAMAMAXMAXXAMXMAMXMAMAASXMAAAMXAMXAAXSAASASXMSMSXMXMASXSASMMMAMAAAAAA
MSMMMMMSMMAAAAAMASAMMAXXXMAMASXMMXSXMMSSSSXMXMMMASAMXMAMAAASXSXMMSXAAAMSMSAXMMMSSMASASMSSSSMSXSASMSSXXASMXSMMMXMXMAAMXMASAMXMAXASXAMAMMMMMMM
AAAXAAASXSXSMSASASAXXAMXMSAMXSSMSMMXSXAAAMXMAMASXSAMXSASMSMSAMXMAXSXMAXAAXAMXAMAAXMMMSAAAAXAMASAMXAAASAMMXXAMXAMSXMMMASMMASXMMMAMXXMXSXXXAMX
SXSSMSXSAMAMXXXMMSASAMXAXAASAMXSAMXAXAMSMMASASASXMAMASASAMXMXMAMMXAMXSSMXMSASMMSSMXMXXMMMMMAMMMMMMMSMAAXSASAMMSXSAAMSAMASAMAAXMSMSSMSMMMSMMX
AAXMAMXMXMAMMSAXAMASMASMSSSMASXAXMXXSXXAASXMASAMMMSMASASMMSSSSXSXSASAMAASAMMSAAAAMAMXXXXMAMXSMXSAMXXXMAXMASMMAXASAMMMXSXMASMMMSAMAAMSAAMASXM
MAMSASAMAMXSAMXMXSAMXMAXXMAXXMAXSMXAMMXSXMXMMMMMAMAAMMXMAAAXAMXAASAMXMMMAAMXMMMMSSXSXXSSSXSASXAMAMASAXMSMXMAMAMAMAMXMASASAMXAMXASXXMMSMSASXA
AXMMMMAMXAAMASAMXMASXSMSSSMSMSMAAAXXMAAXAMASAAASXMXXMAMSMMSSSMSSXMXMSXMSMSSSXXXAXMXMMXSAAAMAMMMMXMMSMMMAMXSAMSMMMAMAMASXMXASXSMMMAMMXMXMAMMM
SXMAMSSMMMXSMMXMAMXMXASAAXAAMAMXAMXMMSXSASAXASMSXMSXMXAAXMAAAMAMXMXAXAXXXXAMAMAMMMMSASMMMXMAMAXSMSASAXMAXXMXSMAMSMSAMXSXMXMMMSMSAMSMAMXSMMXS
XASAMAMXXMAMXMSSXSASXMMMMMXMSXMXMMXSAAMSAMMSAAMXAAMAMXSMSSMSMMSSSMASMXMMAMMMXMASAMMMXSAXXXXXXMSAAMASASMSMXXMAXAMAMAMXAMAMXAAAMASMMAXASXXAMAA
SXSASMMMSSMMSMMAASAMAXSASAXMXXMAAAAMAMXMXMXAMMSSMMSMMAXMAXXXAAXAAXAXMAMAAXAAASXSXSAMXSXMXSXSMXMMSMXMAMAAXSXSXSXSXSMAMMSASMSMSMAMASXSXSAMMMMS
SASXMXAAMAXMAAMMMMXSXMSAMASMAASMMMSSSMXSAMXMSAXXMMAAAXSXSXMXMMMSMMMXSAMSMSSSXSXSASMSMSXMXSAAMSXXAMMMSMMMMXAXAMAMAMXXXMSAXAAAXMASXMXXAXMASAXA
MAMXMMMMSAMSSSMMXSAMXXMAMSMMMMXSAAAAAMAMAMXXMMXSASMSMSSMMASXAAAAAAAAXXMAXXXMASXMAMAMAMMMAMSMMSMSMSASAMMAMMMMMMAMAMSSMMMXMSMSMMMSAMXMMMXXSASA
MAMAMXMAMAMXAAXMAMASAXMAMXAXSXASMMMMMMASAMXAAXAXMAXAXAMAMAMSSMSSSMSSMMSMXMMMAMXSMMXMAAAXXXAMXXAAASXMAMSASAAAXSXSMSAXAAAMXXMAXXASAMAMSASMMMMM
SASAMASASAMMMMMMASXMMSSMXSAMXMMXSAXXXSASASAMXMMSXMMMMMSSMAMAMXAMAMAMXXASAAXMASMSAXXSMSSSMXSMMMSMMMMSSMSASXSSMMASXMMSSMSMSAMMMMMMAMAXAAXXAXAX
SXSMSMSXSXMSASXSAXAAAMAAXMSMXASASXSMAMAMAMXMASAAMXASAMAXSAMAMAMSXMASXSASMSXSXMAXMMMAAXAAXAMAMAMMXMXAMXMAMMMMAXAMAAXMAMAASAMAXAAXMMMSMMMSXSXS
SXMAAAMAMXXXAXAMASXMXMAMXXAXXSMASAAMXMAMXMMSAMSSXSXXASMMSMSMSSXMMSASXMXMXXAXAMAMSMSASMMMMXMAMXSMAMMMSAMAMXASXMAMAMXXMMSMSMMMSMSAAAAAMXAMAXAM
MAMSMSMMSSSMSMAMMMAAAMSXSSMSXXMAMMMXXMASXAAMMMAXMXXSMMXAMXMAMMASAMMSMSASAMMMMMXSAAXMMAAMXSXSSMXMAMMXSXSXXMMAXXSMSMSSMAMAXXAXAAXMSMSMSMMSSMAM
MAMXAXXXAAAAAMMMSSMMMMMAMXXSXMMSSXSAMXAMMMMSSSMMMAASASMXSAMAMXAMMMMXAXAMXSXAAMXMMSMMSSMMASXAXXAXMSMAMXMXAXSXSXMAAAAAMAMMMXMSSMMXMAMASAXAXAAA
SASMMMSMMSMMMSSXMAXSAAMAMMAMAXXMAXAXMMASMSSXAXXAMAMSAMXAXASMSMMSXAXMSMXMXMMXMXAMXAXXAAXMASMAMSMMSAMASAAXMMSAMASXMMMMMXSXSXMAAXXXMAMXMXMASMXS
SXXAXAXAXXASXAAASMMSMSSSMMASXMMSSMSXSAXMASAMXMMMSXXMAMMMXMMAAXAMMXXAXAAMXMASXMASMMMSSSMMASAAAXAXXAMSSMSXXAMAMMMAXXMASMMASAMSSMMMMSSMAXMXSAMX
SXSMMXSSMSAMMMSMMAMXMMAMAMASXAMMMAAAXXXXXMXSXMMAXMASAMXAAMMMMMXSASMMMMXSXAMAMSAMASAMXXAMMMXSXSMASXMAXAXMMMXAMAXSMMSASAXASMMAAAAXAAMXMASAMASM
XXAAMXMMAMXMAMAASMMSXMXSXMASMSMAMMMSMMMXMMAMMXAMSXASAMMSXSAMXMXMASXSAXSAMXMAXMASAMASXSMMSMMMMAAAAAMMMMAXAMXSSXXMAMMMSXMXSXMSSMMMMMMAMAMAXAMX
SMSAMASAMXASASMMMAAMXMAXAMXSXAMASAAXMAAAXMAMXMMSXMXSAMAAASXMAMSMMMXAXMAAMXMXMSAMXSAMXAMAMXAMSAMMMMMXASAMSMAMAMASAMAASAMXSAXAXAAMAASXSSSSMMSX
SAMMSAXSAMXSXSXASMMMAMASXMXSXMXAMMSSSSMMSSMMSASMMSMSMMXSAXXXAXAAAXSMXASAMXMMMMXSMSXSSSMSSMMXMXXAAXXSXSMAAMMSASMXASMMMASASMMXSMMSMXSAAXAXMMMX
MAMAMASAMXMXAXMASMXXASMAASXSASMMXAAMMMAAXMXAXMAXXMAMXAMXMAMSMSSXMXAXMMXXMAXAMXMMAMAMAAAMMXMAMMMXMXAMXMMSXSMMAMXSXMMMMAMASXMMAMAXAXMMMMAMMAMX
SAMAMMSXAAMMXMMMMMMSMSMSXSASAMASMMMSASMSMSMMXSSSSMMMMMXAMXXAXXAASXMXSAMASMSSMSMMSMAMXMASMASXSASAAMSMSXAMXSAMXMXMASASMSMMMAMMMSXSMMMXAAAASASA
SXSSSMMMSAMXASXAAAAAASXMASAMAMAMASAMXSAAAAASAMAAAAXMAMMSMMSMXMSMMAXAMASAMMAMXAAXXXXSXSAAXXSAXASMXMAAMMSSMMASMMMSMMAXSAAAXAMSMMAMMAXMAXMXSASM
XXAMXAAAAAMSMSSSMSXMXMAMAMASXMXSAMASXMXMSMAMMSMSMMSMXSAXAMXSAMASMXMMSAMMSMAMMMMMMSXMAMSSXXMAMXXMASMSMAXAASAMAAAAXMXMXSSMSMSMAMMMSMSAXXSAMAMX
SMSSSSSSMAMAAMAXAMXSAMAMXSXMAMAMMSMMMSAMXXSXXSAMXMAAAMASMMASXSASMAAAMAXSAMMSXMAMAAAMXMMMXAMXMSASAMXXMXSAMMMSSMSSSMAMMMXMAXAMSMSMXMMMASMASXMS
XAXAAXMAXAXMMMAMXMASAXXXMXAMXMMSASAAASASAAXXSMMMSSMSMAAMAMASXMXMMXMAMXMMASAAASAMXSSMAMAAAXXAAXAMXSAMXXMASMAAMAAXAXXXASASMXMMMAMAMXMAMASMMMMX
MSMMMMSMMMSSSMXSAMXMAAMSSSXSASXMAXSMMXXMASMMXAAAXAXAXMXSXSXMXXXAAXAMSMSMSMMMXSAXAXMAMSMMSMSASMAMAMXSSMMAMXMASMMSSMSMAMMMXXMAMSMSSMSXXMAXAAMX
MAMXAAXXMSAAXAXSXSAMXSAAMAAXASMMMMMMXSSXXAAXASMSSMMAXXMMASAXXMMSMMMXAAAXAAXXAXAMSSXSXSAMXAMAXXSMASASASMXSXXXXAXXAAAMXMSMSASXSAAAAAAASXSMXMXM
SAMXMMSAMMMXMMMMMSXSAMMXMMMMSMXAMAXSAXMASXSXMMAXXXMSXXASAMAMXXAAAAAMMSMXSXMMMXAMXAXMMSAMMSMAMMXSASMSAMXMAXMMSMMSMSMSAAAAXMASMMSMMMXSAAMASXSM
MASXAMMAXXXXAAAMAMAMXMAMXAAXMASMSSXMXSXXMXMAMXXMSXMAASMMXSAXXMSSSMSXXAAAMXMASXSXMMXMAXMMSAMXXXAMXSAMXMMXMASAAAXMAMASXMMXMXMAXXAXXXXXMAMASAAX
SAMXMXSMMMXXXMXMASXMSMSMSSSSMXMAAMXSAMXSMXSAMXAMXAMMMMXAXSAMXXMAXAXMMMMMXAMASAXXXXAMMSSMSMSMMSMSAMXMSXMASMMXXSMXAMAMMXSSMAMMSSMSSXMXMMSAMXMM
MXSXXAXAAAXMSSXMXSAASAMXAXMXMSMMMSMSAMASXAMASXAXSSMSXMMSMMMMMXMXMXAXXXAMAXMASMMMMSXSXAXASXSAAXMMXSSSMAXAAMASMXMMMSXSXAAXSASXAXMAMMAXXAMAMXSM
ASXMMSXSMSASAAASMMMMMAMMSSMAMMXXAAMXMMASMMSAMXMMMAAXMAAXAMASXSAXMMSMMSASMXMAXXAAXMAMMMMMMASMMXSXMAXAASMSSMAXXAMAMXAXMMMXMMSMXSMAXSXSMSSSMASX
XMAMXMAXAMMMMSMMAAXAXXMXMMXAMXXMSMSSSMASAMMMMXMASAMMAMMSMSAXSAMXXAAAXAXAXAMXSSSSSXMSMMMXMAMAAASAMXSSMMAXXMASMMMSSMMMXXSMSMXMASMMXMAMAAAAMXMM
SSMMAMSMMMAAXMMMMSSMSMSSSSSMSXMAMXAAXMXSMXSSSMMAXAMXXAAMAMXSXMAMMSSSMMMMSMSMAAXXMMMAAASAMXSXMXSAMMXMAMXMXMAXAAAAAAXAXXMXAAXMASAMAMAMAMSMSASX
XAMMXMAAASXSSMASAAAXAAXAAMAAMMASXMMSMXMSAXAAAXMSMMMSMSAMXMSAXXSXAAXAAXAXAAAMXMXMMAXSXMMAXXSMSASXMMAXMMMSAMXSMMMSSMMSMASMMMXSMSMMMXAXXXAMXASX
SMMASXXXMAAMXXAMMMMMMSMMMMMMMASXSMAAAXAMXMMSMMXAASAMAASXAMSMSMAMMSSSMSSSMXMXMXXMASXMASXSMAXAXXSXSMMMXAXMAMASMAXXMMAMXMSAAAXXAMASXSMSMMMSMMMX
XAMASMSMMMXMAMMXSAMSXXAXXXMXMSAMAMMMXAMXXMXAXAMSXMASMMXSMAXXAMMAMAAAAXMXMASMSAXXXXASAMAXMSMSMASAMASMSSMSAMAMXXMAAMASMXSMMMSMAMXMAAAAAXAAAAXM
SSMMMAAXMXAMXMXAMAXSASXSSMMAXMASMMMAMSSMXSXSXXAMXSAMXXXAMAMSMSXSMMSMSMSASASAMASMMMMMXMMMXXAMMAMAMAMAAAAXXMMMSMSXMXAMAMMMSAXXXMXMXMSSSMXMXMMX
AAAMMSMSSSMSAMMMSAMMAMAXMASXXSMMXASMXAAMASMAMSSXMSAMMSMXAAMAXSAXXAAXXASASAMXMXMXAAXMAMXMMMSMMXSXMASMMMMXSAAASXSMSMMSSXMASAXXMMAAMXMAAAXSSSMS
SSMMAXXAXAXSMSMMSXSMAMXMXMMMXAXMSASXMSSMASMAMXMAMSAMMAAASMSMMXXSMXSXMAMMMXMXXXXSXMMSAXAAAXAXMAMAMASXXMXMMAMXXASASXMAXAMASMSAASASMAMSMMMAAAXA
MAMMXSMXSMMMXMMAMXSAMSXSXMAAMMSMAXMAXXXMASXMXSAMXSAMSMSMXXAXSSMXMAMXMSAMXMMMMMMSAMXSMSSSSSSSMXMAMMSXMXAXXXMSXAMMMAMASASAMAAMXMAMXAMAASAMSMMM
MAMXAAAMSASXAXMMMAMSMMAMAMMSMAAXMAXMMAXMASAMASAMXMAXAAXMXSMSMMAAMASAXXAXXAAAAAASMMXSAAAAAAMAAAXAXXXMMSMXXAAXMMMXSMMMMMMAMAMXXMMMSMSSSMSXXAMX
MSMMASXXSAMMMMMMMXSAMXAMAMXAMSSSMSSMSXXMASAMMSAMMXSSSXXMAMXMXASASAMAMMMMSSSSSMMSXMXMAMMMMMMMXMASMMAAXAAASMSMAAAXMASAAXSXMSXXSSSMAXAXMAMXMASA
AAAXXMAXMSMAMASAMXAMSSSSXXSXMAAAXAAXSAMMASAMXSXMMSMAMSXMMXAMXXXAMXSAXAAAMXMXAXAXAXAXXMXMAMAXXXAXAMXSSMSMAAAXXXSMMAMXSMMASAMSMAASMMMSMAMAXAMA
SSMMMAMXXAXXSASAXMMXAAXMAXMMMMSMMMSXXAMAXSMSAMAXXAMAMXSXSSMSAMMAMASXXXMMSAMMSMSXMMSMMMXSXSXXXMAXASXMXMAXMSMSASAXMASMMASMMSXAMSMMXAXAMMSSMMSS
XAXAXSXMSMSXMASMMSXMMSMMMSMAAXAAXXMAMSMXXSMMASAMSXMASMMMAAAXAXSXMXMMMSAAMAMAXMXAAAXAAMASMAXSSMSSMMXMASMSMAXSMMAXSXMAXMMXAMSMXMXXXMSSSXAXAXAX
XAMXMXAMXXAAMXMXAAAXMAMAAXXXSSMSXMAMXAAXAMASXMAMAASASAAXMSMMMMMXMAAAAXMXMSMMSASMMMSSMSASMAMXAAAXASMSAMXAXMXMXMAMXMMSMASMSMAMAMSMSMAMMMMSAMXS
XSMSSSSMSXSSXSAMMSXMXAMASXXSAMMAASAMMMMAASAMXSXMMXMASXMSXAAASAMAMXMMSSSMAMAMMAMXAXXXAMAXMASMMMMSMMAMASXXMSAMXXXMAMAMMMMAXSMSMSMAAMAMAAXAXMXA
AMAMAXMASAAXAMAMXMMMSMXAMAXMASXSMMAXSAMSXMAXXMMMMSMAMASXXMSMSASMXXASAAAMAMAMXMMSSMMSXMMMSMSXMAXXAMXMMSAMXSMSSSSSSSMSAXMSMXXXXMMSMSMSXXMMXMMA
MMAMMMXAMMMMXMASMAAMAMMSMMMMAMAMASAMSAAAAMSMSMMSAMMSSMSASXMMSAMAAASMMSMMSMMMXXAXAAASAAXAXXSASMSSXMSMMMAXMXXAAXAAAAASAXMAMMMSSMAMXAAXXSSXMSAS
XSXSXMMSXAXXXMAMMSMSMMMAAXSMSMXSAMAXSMMSSMXAAAAMASAAAXMAMMMAMSMMMMXAXMXMXASAMMSSSMMSSMMMXASAMAXXXXAXASMMSMMMSMMMMMMMAXMASAAAXMAMXMSAMXAAAAMM
MAMXAXAXSSSSMMAMXMAMMASMSMAAAXXMMMXMXSAMAAMAMMMSMMMXXAMXMAMASXXXXXMSMXMMXAMASAAAXXMXMMASAXMAMXMMSSMSXMMAAAMAAAAXASAMXASASMSSSMASAMXAMSMMMMXS
SAMSSMSXAXXAXSASAAMXSMSAMAMMMMMASAXMAMSSMMMMXMXSXMSSMSXMSSSMSXSMAXAAMXAAMSMMMMSAMXSSMMAXMMSXMXAAAAASXMMSXSMMMSMSASXSMMMASAAAXXASMSMMXSAMXXAX
XAMAXAXMMMSSMSASXSXAMXMAXXXAMXSAMMMMAMMMXSAMMMAXAXAMXAAXAAAASAXSXMSASXSMMMAAXXXAMXSAMMSSXXXMSXMXMMXMASXAAXASAXAMXMXMAXMAMMMSAMXMXAAXAMMMMMMM
SSMMASMMMAMXAMAMXXMAMAMSMXMXXXMASXAXXMXAASASAMSSMMSSMSSMMSMMMMMAXAMASMXAXMMMMASAMXSAMAMAXXSASXSSSMASMMMSXSAMMMAXXMMSAMMASXAXMSMMSASMMXAAMMSA
MXAMAMAXMMMMSMAMXSAMXSXMAMSMMMSAMXMMSAMMMXAXMXMAXAMAXAXMAMMMAAXMASMXMAMMMXXAMMSAMXSMMAMMXMMAMXXAASXSXXXXAMXMMSSMMSAMXSMMSAMXAAXAMXXASXSXSAMM
SSMMAMAMMSAAMSMSAXSXMXAMSMAAAAAASAMAXXXSAMSMMSMSMSXMMSMSAMMSSSSXSMSSMSAXMASAXAXAMXMASAASAMMAMXMSMMMXMASMAMAMAAMAMMMXMSAXSAMMSXSMMASMMAAAMMMX
MXASXSSMAMMSMAMMMSMSASAMXSSSMSSMSAMXSXXMAXXASAAMMXAXXAASXSAMAMXXMAMXAMMSXXAMMXMAMXMMMMXXAXSSSSMAXAAAXAXAXMSMMMSAMMSAASMMSAXMAXAXMAXXMMMMMMXX
SXMMMAMMXSAXMASAMAAAMXAMAXXAMXXMSXMMMMASMMSSMMSMASAMXAMSAMMSAMXSMSMSAXAMXMASAXSXMMXAAMSSSMAMAAXSSXSMSSSSMAXMMMSXSAMMXMMAXAMXMMMSMSMSXSXMAMAM
XASMMMSAMMMMXASASMSMXXAMMSSXMASMSMSAAXAXAAXAXXXMXMAMSMXSAMXSASXXAAAMMMMMMMAMMMMAAMSSXSAAAMMMMMMXAMXAXMAAMXMASAMXMXSSSSMSSSMSXSXAAAXSASXSASAA
XSMAASMMSAMAMMSAMAMAMSSMAAXMMMMAMASXSSSSMXSMMMMSASAMAMXSMMXXAMXMSMAMAAAXAMAMSASMSMMAMMMSMMXMAAXMASMMMMSMMASXMASXSAXMAXAXAAAAASAMXMXMAMASXSAS
SXSMMSAASASMAXMAMAMAMAMXMXSMASMAMMMSXXXAMMAXAXAMASXXASMMASAMSMSMMXSSSSSSXSXSXXXMAXMAMSMAXMAXSXMMAMAXXMAXSXMXMAMMMXMMMMSMSMMMMMMXAXAMAMMMXMAM
AAXMAXMMSXMXXXXAMXMXMMSAMMMMASXSMXMXMSXXMAASXSSMMMMSASXSAMAXMASAMMMAAAAAASMXMMMSAMXXSXSAXMMMXAAMSSMMMSMMMMSSMAMMMMSMMAAAXAMXAAXSMSMSMSXSXMAM
MAMXMXSAMASAXSSSMMSMAMSXSAAMMSAMXAMAMASXXSMMAXAXAAXMMMMMXSMMMMMAMAMMMMMMAMMAXAAMAMMSMMMMSMSAMMMMXAXMAAMAAAAMXAMAAAAAMSSSMSMSSSXMXAMAXXAMSMAS
MAMAMSMAXAMMMMAAXAAMXMMMXMMSAMAMSMXSAMAMMXAMXMXSMSMXSMSAMXAXMXSXMMSAMXAMAMXMMMXSAMXAAAXAAAMMXASXSAMMSMSMMMSXSSSSMSSSMMXXAAAXAMXXMSSSSMXMASAS
SASASXSAMXMSAMAMMSXSASASMSAMXSMMXSAMMXMSSSMSSXMAXXASAAXAAMXMAMMAAAXASXXSXMASASXSXXXSSMSMMSMSSMSXMASXMASXMAMXAMAMAAAMMSXMSMMMMMXSAXAXMASXXMXS
SAXMSXMXSAASMSMSXXAXXXASAMXXXMXSAMXMXAXAAAAMXSSSSSSSMMSXMSMSMSSMMMMXMMMMMSMSAMASXMXMMMSAAAAXAAMXSAMAMMMAMASMSMAMMMSMASAMXSAAAAAMXMMMSMASXMMM
MSMXXAXAXMMMAAAMXMMMSMMMXMSMXSAMXAAMSMMMSMMMAXXAAXAMXXMXXXAAAMXAAMMMXAAXAAXMAMSMMSAAAAMAMSSXMMMAMSMXMASXMXSAASASAAXMMMXMAMXSMMXMMAXAAXAXMXAS
AAMXMMMSSSXMSMSMMMAAAAAMAAMAXAXSSMMXAAXAAMMMSSMMMMMMMAXSMMSMSMSMMSAASXSSSSSMAMXAASXSMSSMMAAASAMXSXMASASASAMMMSXSMSXSAMXMSSXXMMSAMSMSSMMSASMS
SMSAMXAAAAMMMXMXXMMMMSMSMMMAMMXXXASMSMMSMMMAMAXSXMXMSMXAAAAMXAXXASMMMMAXXAAXMAMMMSAMAXXMMXSMMAXSAXMAMXSXMASAMXXSAMAMMSAAAMMSAASAMXAMXMAAMAMX
XXSASMMSSMMAXMASMSMXAMAXAXSAMXAMMMMAXMAAAAMASXMMXSAMAMMMMMSSMXMMMXMMSMSMMXAMXAAAAMAMSMAXMAXASMMMAMMASXMXSAMXMXMSAMSMASMMMMAMMMSAMMSMMXXSSSXS
MASXMAMAMXSASXXAAAAMSMSMMMXAMXAXSAASMMSSSMSASAMXASXSASASAMXAXAMSMMSASXMASAMXSMSMXSXMASMMMMXMXAXMAMSASASASXSXSAASMMXMAXXAXXSXSXSAMXMASXAMAMMM
MAMASXMAXAMXAMXMMMSMMAXAMAMXMSXMSAXMAXAMXXMXMXMMMSASASAMASMSMMMSAXMASASAMSAMXMAMXMASMXMXAMMXSAMSMXMXSXMAMAAASMMMAXSMXSMAMXMAMMSMMMXMMMMMAMXM
MSSXMAMMMSSMMXAXAAXAMXSXMAXSAXAXXMMSMMSSMSXXMASXMXAMMMXSAMXAXSAMMMMAMMMAMAXMASASAAXXXMASAMAMMMMXMAMMMMMSMAMXMAASMMSMMAMASMMAMXXAAAASAMXSXMAS
MAMMSSMXAAAAXMSMMXSAMXMAMAXMMSMMAAAXAAMAXXAASAMXXMXMAXMAXXMMSMAXSAMAMXSMXMASASXSMSMXSAMXSMSXSASXSAMAXAAMAMXXXSMSXXXSAAXMXAXXSSSSMSXXASXMXSMX
MXSAAAAMMSSMMAMXXXAMSMSAMSMSAMXSSMXSMMSSMMSMMASXXXSSXSMMXMAMAXAMAMSAXXAAASAMASXSXAAMASAAXXMASASASXSSSMSSMSMSXAAXXMASXSMSMSMXMMXAAMMSXMAMASAS
SAMMSSMXMAXAXSXAMXMMAMMXXXASXSXXAMMXAXXAXXMXSXMXSMAXSMXAASMMSXMSMASASAMSMXAMSMAXSXXXAXMSSMMMMXMAMAAASAMXAAASAMMMAMXMAMASAXXAMSXMMXMASMXMASMA
MASAMXMXMASXMXMASAXSASMSSMXMAMXSAMSMMMXXXMMASAMXMAAMASMSMMAXAAMMXMMMMMXMXXSMMMXMAMMMMSAAMAMXSMMSMXMSMSMMXMSMAXAXXXAMMMAMMSAMXXXMXXMAMXXMMSXM
SAMASXXMAXSXMMAXXMMSASAMXAAMAMMMXMXAAAMMMSMASASMMSXSAMXXASXMSSMSAXMMAXAXMAMAMASXXXAAAMMMMAMMXAMXMMXMAMXXMSAXSMMMSSMSSMASXMXMAXMMXMASXXSXMMMX
MASAMMASMXSAAASMMMAMXMMMMSXSASXMSASMMSAAAXMASXAAAMAMAMSXMXSAAAXSAMXSSSMSXAMAMAMMMSMMSXXXSMSASXMAAMAMMMSMMSAMMAAAMAXAASASAMSMSMSAMXAMMMXXXAAX
SMMMXSXMMASXMMMAMMAXAMMXAXASMSAXMASAAXXAMXSMSMMSXMASAMXAMAXMSSMMASXMAMMMMMMAMASAAAMAXXMXAMXXMMSSMSMSAAXSAMXMSXMMSMMSXMMSAMAAAAXXAMASXAAMSMSM
MXAMMSSMMASAXAMAMMASXSAASXMMASXXMAMMMMXMXXSAMXXMASAXMXMAMXMAMXAMAMAXMASAASXMSASMSXMASASXXXXMMMAXMAXXMSSMSSSMSAMAAXAMXMASMSMSMSMAAMMMMMMXSAAA
SMMSAXASAAXAMXSSMXMAMXMSMASMAMMMSMSAMXMMMMMMMMASMMMSAMSSMSAMXSSMASMMXMSMMSAAMASMMXMXSAMMMMMSAMXSMSSSSMAMMSXASAMSXMXSSMAXXAMXAMASXMSMSXSAMSMS
AAMMMSMMMSSMSAMXAMXMASMAXXMMMXXAAXMASAAAASASAXMAMAAMAMAAASXMMAMMXMAMAMXMXSXMSAMAAAMMMXMAXAASMSMSAAAMMMAMXXMMMXMXASAMAMASMSSMXMAMXMMAXAMMMAMA
SMMAAAAAAMAMXXXAXMAXXAXMXSXXSAMXSXMASXMMMSASXMXAMMSXSMSMMMAMXMSXSSMMAMMSAMAMMASMMXSAMXSSMMXXXAAMMMSMXXSXMMMSAMMXSMASAMXXAMMXMMAMSMMMMXMXSASX
XAXMSMXMMSAMMMSMSSMSSMASAXXXMASXAXSASAMSAMMMMXSXMAMMAAAMASAMXXAAXAMSAMAAMSAMSXMASAXMAXAMXMASMMSMSAMXMMMASAASASMXXMXMASMMSMXAMMMXSAAMSMSAXMMM
SXMMMMSAMSASAAAXAAAAASAMASXMSAMMAMMASAXMAMMAAMMAMAMXMSMSAMMXMMMSMMMSASMMXMAMXASAMMSMMXSMXSAMXAAXMASXMASMMSXSAMXMMXMAXMXAMASXSASXSXMSMAMMXSAM
MMXXAXMAMSASMSSSSSMSXSMSMMXMAASXMMMAMXMSAMSMMSSSMMMXXAAMXSSSMAAAAAAMAMXXSSSMSXMASXAXSAMXAMMMSSXXAMXMMXXSAXMMMMMXSASAMXMSMAAASASMXXMAMMMAAMAS
XXAMMMMAMXXXAAAMAXAXXMASXAXSXXMXAAMSSXAAAXAAAXXMASAMXMXMASAASMSSSMXMSMMAAAXASMSSMXASMMMMMSAXXXMSMMAXXASMMXMAAAXASAMXAXSAMXSMMXMXSMSSSMMMMSAM
MMXMAMSMSXMMMMSMMMSMSMMMMSMSMSMSMMMASMSSSMMMMSASAMASAMSSSMSMMXAMMMXXAAMSMSMMMMXXAXMAAAAAMAMMMXAAAMXSSMMXAASMSMSAMAMASMSAMMAXAASMMAAAAMXAXMXM
SMAMAXAAMAAMAAAAXAMAMXAAAXAMAAAMASMMXXAMMAXAMSAMASAAASAMXAAXSAMXAAMXMMMAMAXMXMAMXMAXSMSXSASAAXSXSAMXMAAMSXSAAAMXMXMMMASAMAMASXSAMMMSMMMMMXAM
AAMSSSMSSXSSMSSSMSMAMSSSSMAMSMSMAMAXSMSSXSMMMMXMAMMSSMXSMSMXAMXSMSXSAAMASMXMAMASXSSXMAXXSAXMSMAAMMAASMMXMAMMMMMMSMSXMMMAMMXXMASMMXAXAMSSSSSS
MXXAXSXXAAXXMAXMAAMXMMXMXMSMXAXMAXXMAAMXMXASXSAMASXXXAXXMXMSMMMXAAAMSMSXXXASXSMSAAXSSXSMMSMAAAMXXXSXSMSXSAAMASAAAAAXAXSXXXSAMXSXSMMMAMAAAAAS
XMMSSMSMMMMASXSMSMSSXSMMAXXASXMMSASAMXMAXXAMASASASMSMSMXMAMAAMMMMMSMXMAXXMAXAAXMMMMXSASXAXMMMXAMMMMAMAMAAMMSASMSMMMAMMXMXMSXMASASASMSMMMMMMM
MXAXMAXXMASXMASAAAXXAMMMXMMXMAMAAXSSSMSSSMAMXMAMAXAMAAXMXASMSMAAXAXMXSAMMMSMSMMXMASAMXMMMSMSXAXAAAMAMAMXMAAMMSAAAAXAMMAMAMXASMMMMMMAAXMASMXM
AMSSMSMSSMSAMAMSMSMMXMASMMSMSMMASMMASAAAAMMMAMXMSMMMSMMSSMSAXMSMSMXSAMASXAAXAAMXMAMASXMXAAAAMAMXSMSMSAMXMMSSMMMXSMXXAXAMAMMXAXAAAXMSMMMAXAAX
SAMXAAAAMXMXMXMXXXXMMMASAAAAASXAMAMAMSMSMMMSASMAMAAAXMAXAXMMMAXAAAAMASAMMSSSSSSMMXMXMXXASMSMMASAAASMSAMXAXXAXAMMMASXSSMSASMSMSXSSSMAMAMMSSSS
MAAMMMSMSMSMMMMAMXMMAMASMMMXMSMSXMMXMAXAXMXMAXMASXMMSAMMAMMSMAMSMMMSXMAXXXAAAAAMMAMXMSXAMXMASASMMMSASAMSSMSMMSSXMAMAAAASAAAAXAXMXMMXMASXAAAM
SSMMSXAXAAAASAMAAAASASAMAXSXXXAXXSAMXMSMSMAMSMMMSAAXMASMSAXAMXMAAMASXSAMMSMMMMMAMASAAMMMMMSAMASXSAMAMAMAAXXXMMXMMMMMMMMMAMXMSMMSAMSXSASMMMMA
XAXSASMSMSMMSAXASMMAMMXSAASXMMSSMMASXXSAAXSXXMSAXMMMMAMAXSSMSSSSSMASAMASAAAAXXSMSAMMXMSMAAMMSMMAMASXSMMXSMSXXXSAASASXXAXMASXAAAAAMAAMAMAXMXM
MMXSMMXAAXMASXMXXMXAXAXMMMMAMXAXAAAXAXMXMXXAMAMMSSMMMASASXMXMAMAMMMXXSAMMSSMSXXXAMSSMMAMMXMAAAMXMASXAXAXAMXSAASXXSAXMMASXMASMSMSMMXSMAMSXMSS
SXAMXMSMMMSMMMMSAXXMMMXXAASMMMMSSMMSMMMSMSSXMAMXAAAAXAMXSAMXMMMAMMMMXMXMXXAMXMMMMXAAASMXSAMSXSMSMASMMMXMAMAAMAMAXMXMSSMSXMXMMMXAMXAXMXSXAAAM
AAMSAMASAAAXMAMSAMXSAMSSSMMAAXMAXXMAXAXAAAAASXMMSXMMMMSMXAMXMASASAAXSASMMSAMXAASXMSSMMAAMMXMAAXXMAXAASMMSMSSMAMSMSAMMAAXXMASASMMSMXSXXMAMMAS
MSMMMSASMSMXSSXXXMAMASAAMXXXMXMXSMSXSMSMMMMMMAXXXASXXAAAXSSXSASMSXSSMAMAASMMMSMXMAMAMMMMMSAMAMMXMAXSASAAXAMXXMAXASXXXMMMASASXMAMMMMXXAMXXXAX
SAMXAMASXAAASXMASMSXMMMSMSMMSAMXSXSXSMAXSSXMSMSAXMMAMSXSXMAMMMSASMMXMMMMMMXSAAXMAMSAMSMMXMXXAXAXMAXMASMMMAMXSMMMXMMSSSXSXMXSMMMMAAAAAMSASMMS
SXMMMMASXMSMSAMASXXAMAMAASAASASASAMASMMMAMAMAMXMXXAMXXXMXMAMSAMXMASMMAAAXAAMXSMMMXMMMAAAXMASMSSMMMSMAMAXSXMAXXMXSAXAAMMMAMASAASMSASXSASAMXSM
MMSMSMASXMXXXAMAMASXMASMSSMMSAMXMAMAMAMAAMAMAXSXXMAXASMMXSAMSXSXXXMAXSMSMMSSMMMXMAAAXSSMXMASAAMXXMAXMMMMMAMMSASAAXMMSMAXAMASMMSAXXMAMAMXMMAX
AMAAXMXMMXMASMMXSAXAXAMMAMXAMXMXMSMMSAMXMSSSMXSAASXMXSAAAXAMSAMMSMSSMMAMAMAXAAAAMMMMMXAMMMASMAMMXMSMSMSASXMAMMMMSXAXXXSSSMASAXMAMAMMMXMASXMX
XSMSMSAAMSMAMAAXMASMMSSMAMAMSAMXAMAXMXSXAAAAMAMAMASXXXMMSMMMMAMAAXAMAMAMSXMXSMSSSSXSXXAMXMASXMMXSSMAAASAMMMMXXAMXMSXMAMAAMAXMMMAMAMXSXSASASX
ASAMASMMMAMASXMXAAAAAXAMSSSMMAXXMMAMAASMMMSMMASAMMMMSMSXXASMSMMSSSMMMSAMXASAMAMAAAASAMSMSSMMAXAMXAMMMMMXMASAMSXSXAXMASMSMMSSMMXXSASAMAMXSASM
MMAMMMSSSMSASMMXMXSMMSSMMAAMSMMSMSMMMAMAXAAASXSMSXAAMXMASAMAAAMAMAXMASMMSAMXMAMMMMMMAMAAXMASMMSMSMMAXAXASMMXMXAMMSMSMMXXAAAMAXSASASAMXMXMAMA
XSXMXAAXAAMAMMSASXXAAAAAMSMMAAXAASMMXASMMMXXMAMXXMMMSAMXMAMSSSMXMXMMAMAMAAMXSMSXXAXMXMMSMMMMMAAASXSMSMMMSXXXSMXMAMMSAMAXMMMMAMMAMASAMXSSMAMS
XMAMMMMMMXMSMXMASXMMMMSMMAMSXSMMSMASXMSASMSSMAMMMSAASAMXSXMAMAMSSSXMASMAMXXAAXAMSMXMAXAXMMAAMMMSMAXXAAASMMSAAASXXSAMAMXMXASMSMMAMASAMXAAMMSM
XXAMXAXSAMXAMMMSMXMAMXMAXAMMMMMXMMMMAAMAMAAXSMSMAMMXXAMXMAMASAMXAMSSXSXMXMMSSMMMAAASAMXSXMXSSMMXMMMSMSMSAASXMMMAAMASAMXSMASAAXSXMXSXMASXMSMM
MMSXMASXASXMSAMAAXSAMSMSSSSSXMASMASXSMMMMMXMMSXMMXXSXSMAMAMMSMMMAMASAMXXAXMAXAAXMXMSAMXXAMSMXXXMASAMXXMMXMSAMXMMMMXMASAMMAMMMXMAMAMXXMASMAAA
AXAAMSMMMMAAMAMMXMAAXAAMAXAXAAAMMXSAAMAAAMXMXAMMSMMXAMSMSXSMMASMXMASXSMSSSMSSXMSSMXSAMSMSMAASMSSXMAXAXXSMXSXMAMAAXXSXMXSMXSXSASAMMSMMXMAXMMM
SMMSMAAXXSXMMSMMASMMSMSMXMASXMASXSMMMSSSXSAMSMXAAAXMXMAXAASASAXXMMASAMAAAAAMAAMAMSAMMMSAAMMSMAAMMXMMMSMMMXXSSXSSXSAMXMMSAMXASXXAXAAASAMMSSXX
XAXXMSSMMMASAXASASXAAMXXXAXMASXXXAAAXAAXAMMXAAMSXSMAASMMMSMAMXSAMXAMAMMMSMMMSMMASMXXSAMXMSMAMXAAAASAMXAAMMMXXXAXASXSXMAMAXMMMMMMMSSXSASAAXXA
MMMXMXXAAMXMASAMAXMXSMMSSMXXAMMSSSMMSMXMSMMSMSMMAMMSMSAASMMSMASAXAMSXMAMAMXXAAXSMMAAMMMAMAXXSMSMSMMAXXMMSASMMAMMAMXXAMSSSMXMASAMAMMMMMMMMSSX
MAAAMMSMMMAMAMXMSMMAXAXAAAMMMSAAMXAXAMAMXMAAMAMXAXAAXXMMSAAXMXSXMXXXASMSSSMMSSMAAMSSSSSSSSSXSAMAMXSMMASASMSAMXXMAMXSAMXAMMASASAMMMASMSMXSAXS
SASXSAMAASAMSXMAXAXASAMSSMAAAMMSSSMMASASAMSXSASMSMSMSMSMMMMSMMMXAXMSAMAAAXAXAMXSXMXAMAAAAASAMXMMXMASMMMASMSMMMXXXSAMSAMXMSASXXXMXSAMAAAMMSMA
AAMMMASAMSASMAMSSMMMMMAMAMSSXSAAXAASXMAMXMAXMASXMAXAMAXXASAMXXAAXMXAAMMMSXXMASAXASMAMMMMMMMXMMMMMAAASXMAMASASAMSXMASAMXAMMMXAXSAMAXMSMMMAXXS
MXMXSAMXXXMAMAMXAXSAAMSSSMAMXMMSMSMMSMXMSMMMSAMAMSMSMAMXAMXSAMXSMSMSSMXAMMSSMMASAXXXMASXXASMAMASMMSAMXMAXXSAMSAAXSXMMXSXMASMAMMAMAXXXAMMASMA
SMMXMASXSSMASXSSMMXXMSAAAMSSSXXAAMXMAMAMXAAAMASXMXAXMAMXAXAMMAAXAAAXAMXXAAAAAXAMXMMSXMMSAMXAASMSAAXAMAMMXMMXMMSMMMMMMAMASASMMXSMMMMAMMMMAXAM
AXXAXAXAMASASAMXMAXSSMMSMMMAMAMMXMAMMSSSSXMMSMMMAMXMSASMMMMSMSSSSMSMSXMMMMSSMMXSXAXMASAMMMMXMXMMMMSSMSASASXSAXXXMXAAMXSAMMSAXAXXAXMASASMSSSX
MSXMXXSASAMXSAMXXAXMAMMAAAMAMMMSMSSMXMAAMMXAXAAAXMXAMMXXAAAAAXAAAAXMMAXXAAMAMSMMMSAMSMXXAAMMXSAXAAAAAXASASASXMXMMMSSSXMMXXXMMMSMXXSASXSAAAMA
XMASAMSAMMXAMAMXMMXMAMSMSXSAXXAXMAMXMSMAMSMMSSSMSAMXMMMMSMMMSMMMMMMSXSAMXMMAMXAAAMMXXAMMSXSAASAMSXMMMMAMAMMMAMMSAAMAXAASXSMXAMAXSMMMSAMMMSMS
MXAMAXMAMSMMSSMMSASXMMAXMMMMMMMSMASAMMSAAMAMAAAXSMSMSAMXMMXXMASAAXXMAXMMMXMAMXMMSMSAMAMMAAMMMMAMXAXMMMXMAMASXMAXMSSMSSMMAAXXXMXXSAAAMMMXMAXA
MMSSXMSAAXAMAAAXMASASMMSXAAAXAAAXXSASMXXMMAMMXMMMAAAMXMAASXMSSSXSSSMAMXAAAMAMXXMMAMMXMMMMMMAXSXMSMMMMMMSMSAXAMMSMAAMAMMMSMMMSAMXSXMMSMSAMXXM
XAMAMASMSXXMXSMMMAMXAMAMMSMSXXMMSMSMMXMASMMXSAXAMXMSMXSASXMASXMAMAMMAMSSSMXAXSMSMAMXXSXAASXMXSSXAXAMXAXAAMASXSXAMSSMAMMAAAXMAXMMSXSMSAMXSAMX
MMSMMAXXMAXSMXMAMXSAMXAMMXSXXSMXXAXAAMMASAMAMXSMSAAAAXSMMAMXMAXXMAMSXMMAAMMSMSAAXAMSXMAMMMAMMMMSMSSMSASMMMMAAXMMXXXMAMMSSSMMSMSXMASAMXMAXASM
MAAAMXSAMMMSAMSMSAMAXSXSXXASAMMASMMMMSMASXMASXMAAMMMSMSASXMASMMXMAMMMMMMXMAXAMSMMSSMAMASMSSMAAAXMAMXAAAXASMMXMMSAMSSMSMAAMASMAXAMAMMMMMMXAMA
MSSSMASAASXMAMMXMASAMMXXXAMMSMAASAAXSXMASASASAMAMXSXAAMAMSAMXAAXSMSAAXASMSAMXMASAXAMXAASMAASXMSSMASAMXMAMSAXASXAASAAXAXMASXMMXMMMMSAAXAAMSXS
XXAXMASXMMMSAMXAXMAMSAMXASXSMMMSSMMMMSMASMMXSMMAXMASMSMXMXMSAMXXXASMSSMSXMASASMSXSAMXMMSMSMMXAXXXASXXMASMSXMASXSSMXSMMXXMAMXXXXXSSSMSSXXXMAX
)"""";

typedef enum {
    NORTH_WEST,
    NORTH,
    NORTH_EAST,
    WEST,
    CENTER,
    EAST,
    SOUTH_WEST,
    SOUTH,
    SOUTH_EAST,
} Direction;

static std::vector<std::pair<int32_t, int32_t>> directionMap = {
    { -1, -1 }, { 0, -1 }, { 1, -1 },
    { -1,  0 }, { 0,  0 }, { 1,  0 },
    { -1,  1 }, { 0,  1 }, { 1,  1 },
};

typedef std::vector<std::vector<char>> Grid;

char charInDirection(uint32_t x, uint32_t y, uint8_t direction, Grid grid, uint32_t distance = 1) {
    assert(direction < directionMap.size());

    int32_t targetX = x + (directionMap[direction].first * distance);
    int32_t targetY = y + (directionMap[direction].second * distance);
    if (
        targetX < 0 || targetX >= grid[0].size() ||
        targetY < 0 || targetY >= grid.size()
    ) {
        return false;
    }

    return grid[targetY][targetX];
}

void debugPosition(uint32_t x, uint32_t y, Grid grid) {
    for (int direction = NORTH_WEST; direction < directionMap.size(); direction++) {
        printf("%c", charInDirection(x, y, direction, grid, 1));
        if (direction % 3 == 2) {
            printf("\n");
        }
    }
}

bool isCharInDirection(uint32_t x, uint32_t y, char target, uint8_t direction, Grid grid, uint32_t distance = 1) {
    return charInDirection(x, y, direction, grid, distance) == target;
}

static void parse(std::string input, Grid& result) {
    std::istringstream inputStream(input);
    std::string line;

    while (std::getline(inputStream, line, '\n')) {
        if (line.empty()) continue;

        std::vector<char> lineChars = {};

        for (int i = 0; i < line.length(); i++) {
            lineChars.push_back(line.at(i));
        }

        result.push_back(lineChars);
    }
}

static int32_t countInstancesOfXmas(std::string input) {
    Grid grid;

    parse(input, grid);

    int32_t instancesOfXmas = 0;

    for (int y = 0; y < grid.size(); y++) {
        for (int x = 0; x < grid[0].size(); x++) {
            if (isCharInDirection(x, y, 'X', CENTER, grid, 0)) {
                for (int direction = 0; direction < directionMap.size(); direction++) {
                    if (direction == CENTER) continue;
                    if (!isCharInDirection(x, y, 'M', direction, grid, 1)) continue;
                    if (!isCharInDirection(x, y, 'A', direction, grid, 2)) continue;
                    if (!isCharInDirection(x, y, 'S', direction, grid, 3)) continue;
                    instancesOfXmas++;
                }
            }
        }
    }

    return instancesOfXmas;
}

static int32_t countInstancesOfX_mas(std::string input) {
    Grid grid;

    parse(input, grid);

    int32_t instancesOfXmas = 0;

    for (int y = 0; y < grid.size(); y++) {
        for (int x = 0; x < grid[0].size(); x++) {
            if (!isCharInDirection(x, y, 'A', CENTER, grid, 0)) continue;

            char nwChar = charInDirection(x, y, NORTH_WEST, grid, 1);
            char neChar = charInDirection(x, y, NORTH_EAST, grid, 1);
            char swChar = charInDirection(x, y, SOUTH_WEST, grid, 1);
            char seChar = charInDirection(x, y, SOUTH_EAST, grid, 1);

            if (
                (nwChar == 'S' || nwChar == 'M') &&
                (seChar == 'S' || seChar == 'M') &&
                (nwChar != seChar) &&
                (neChar == 'S' || neChar == 'M') &&
                (swChar == 'S' || swChar == 'M') &&
                (neChar != swChar)
            ) {
                instancesOfXmas++;
            }
        }
    }

    return instancesOfXmas;
}

void day04() {
    int32_t partOneExampleOutput = countInstancesOfXmas(exampleInput);
    printf("Part One Example: %d\n", partOneExampleOutput);
    assert(partOneExampleOutput == 18);

    int32_t partOneOutput = countInstancesOfXmas(puzzleInput);
    printf("Part One: %d\n", partOneOutput);
    assert(partOneOutput == 2644);

    int32_t partTwoExampleOutput = countInstancesOfX_mas(exampleInput);
    printf("Part Two Example: %d\n", partTwoExampleOutput);
    assert(partTwoExampleOutput == 9);

    int32_t partTwoOutput = countInstancesOfX_mas(puzzleInput);
    printf("Part Two: %d\n", partTwoOutput);
    assert(partTwoOutput == 1952);
}
