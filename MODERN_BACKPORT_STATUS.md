# Modern Backport Status — neoLegacy (1.13 → 1.21.11)

**Repo:** Darkmatter655/neoLegacy  
**Base:** Legacy Console TU19 / LegacyEvolved (prismarine + sea lantern already present)

## Honesty rule
A feature is only marked **Fully implemented** when it is registered, behaves in-world, renders, saves/loads, and has been exercised. Names/textures alone are not complete.

## Already on stock main
| Feature | Status |
|---------|--------|
| Prismarine / bricks / dark | Implemented (Tile 168) |
| Sea lantern | Implemented (Tile 169) |
| Coral material + CoralTile class | Partial stub (not registered in staticCtor) |
| Fish item strings (salmon/clownfish/pufferfish) | String IDs only |

## 1.13 Update Aquatic — in progress
| Feature | Status |
|---------|--------|
| Coral blocks (tube/brain/bubble/fire/horn) | In progress |
| Dead coral variants | Not implemented |
| Coral fans | Not implemented |
| Kelp / seagrass / sea pickles | Not implemented |
| Drowned / turtles / dolphins / fish mobs | Not implemented |
| Shipwrecks / ocean ruins / buried treasure | Not implemented |
| Trident + enchantments | Not implemented |
| Conduit | Not implemented |
| Waterlogging | Not implemented |
| Bubble columns | Not implemented |

## 1.14 – 1.21.11
Not started yet. Work proceeds version-by-version after 1.13 foundations compile and play.

## Engine notes
- Tile IDs are fixed 0–4095 (`Tile::TILE_NUM_COUNT`).
- New content must register in `Tile::staticCtor()`, Item tables, icon register, CMake source lists, and `strings.h`.
- Build **Windows64** preset only for PC; Durango/Xbox needs XDK.
- Texture pack reference: Default-Java-1.21.11 for modern assets.
