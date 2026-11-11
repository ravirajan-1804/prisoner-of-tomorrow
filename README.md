# The Prisoner of Tomorrow

A first-person 3D escape-room mystery built in Unreal Engine. The player explores rooms, finds clues and solves puzzles to progress. In development.

- **Engine:** Unreal Engine 5.5
- **Built with:** C++ and Blueprint
- **Project file:** `MyProject.uproject`

## What's in this repo

| Folder | Contents |
| --- | --- |
| `Source/MyProject` | C++ gameplay classes |
| `Content/Blueprints` | Puzzle and interaction Blueprints: keypad, puzzle controller, answer box, question cards, door, torch, interactable interface |
| `Content/FirstPerson` | Main level (`FirstPersonMap`) and the first-person template it builds on |
| `Content/__ExternalActors__` | The level's placed actors |
| `Content/bed`, `Content/models`, `Content/Room_5_assets`, `Content/material_level1` | Room props, textures and materials |
| `Content/lighting`, `Content/Animations` | Fire and torch lighting, opening-scene animation |
| `Config` | Project settings |

## C++ classes

- **`AKeypad`** (`Keypad.h/.cpp`): a four-digit code lock. It collects digits, checks them against `CorrectPassword`, plays click and error sounds, locks itself once solved and fires the `OnCodeCorrect` Blueprint event.
- **`APhonograph`** (`Phonograph.h/.cpp`): an interactable prop with a mesh and an audio component. `PlayRiddle()` plays the riddle audio that hints at a code.

Both are exposed to Blueprint, and `Content/Blueprints` builds the in-game actors on top of them.

## Content you need to add

Third-party asset packs are not included, because their licences do not allow republishing the raw files. The full project is about 3.7 GB with them. To open the level as intended, add these so they land in `Content/`:

- **From Fab:** Necropolis, Medieval Bed, First Person Arms, Essential Footsteps, Footsteps Volume 02, and the Megascans items under `Fab/`
- **From the editor** (Add → Add Feature or Content Pack): First Person and Third Person template content (`Characters/`), Starter Content

Without them the project still compiles and opens, and the C++ and Blueprints can be read, but meshes and sounds from the packs show as missing.

## Build and open

1. Install Unreal Engine 5.5, Visual Studio with the C++ game workload, and [Git LFS](https://git-lfs.com).
2. Clone the repo. The `.uasset` and `.umap` files are stored with Git LFS.
3. Right-click `MyProject.uproject` → **Generate Visual Studio project files**, then open the project and let it compile.
4. Add the content listed above.

## Author

Ravi Rajan · [Portfolio](https://ravi-rajan-portfolio.vercel.app)
