import { assertEquals } from "@std/assert";

const EXAMPLE_INPUT = `
Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue
Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green
`;

const PUZZLE_INPUT = `
Game 1: 7 blue, 6 green, 3 red; 3 red, 5 green, 1 blue; 1 red, 5 green, 8 blue; 3 red, 1 green, 5 blue
Game 2: 9 green, 1 blue, 12 red; 1 blue, 18 green, 8 red; 2 blue, 6 green, 13 red; 3 blue, 13 red, 7 green; 5 blue, 4 red, 4 green; 6 blue, 7 green, 4 red
Game 3: 5 blue, 9 red, 14 green; 10 green, 3 blue; 11 red, 2 blue, 8 green; 5 red, 2 blue; 5 blue, 7 green, 8 red
Game 4: 2 red, 3 blue, 2 green; 17 green, 6 blue, 1 red; 3 blue, 5 green, 1 red; 4 red, 1 blue, 16 green; 5 red, 4 blue, 13 green; 14 green, 5 blue, 6 red
Game 5: 3 red, 17 green, 10 blue; 9 blue, 5 green; 14 green, 9 blue, 11 red
Game 6: 4 green, 18 blue, 3 red; 6 green, 8 blue, 9 red; 4 green, 9 blue, 7 red; 9 red, 1 green, 12 blue
Game 7: 1 blue, 14 green; 1 red, 4 blue, 15 green; 3 blue, 6 green; 3 blue, 2 green, 1 red; 1 red, 3 green, 1 blue
Game 8: 10 red, 3 blue, 3 green; 5 blue, 7 red, 3 green; 3 red, 3 green, 11 blue; 1 red, 7 green, 10 blue; 13 blue, 5 green, 5 red; 1 green, 17 blue, 3 red
Game 9: 1 blue, 6 green; 7 green, 2 red; 3 red, 2 green; 1 blue, 4 red, 3 green; 7 green, 1 blue, 1 red
Game 10: 14 green, 6 blue, 1 red; 8 green, 5 red, 1 blue; 8 green, 5 blue, 5 red; 2 green, 3 blue, 5 red
Game 11: 1 blue, 2 green; 1 blue, 1 green, 7 red; 1 blue, 4 green, 7 red; 2 red, 2 green, 1 blue
Game 12: 5 blue, 12 green, 12 red; 11 green, 3 red; 14 green, 3 blue, 18 red
Game 13: 2 green, 6 red; 6 red, 5 blue; 7 red, 3 blue, 8 green; 7 red, 8 green; 3 blue, 2 green, 3 red; 1 blue, 8 red, 6 green
Game 14: 18 green, 6 blue, 5 red; 5 blue, 15 red, 19 green; 7 green, 11 blue, 20 red; 5 red, 18 green, 7 blue
Game 15: 3 red, 16 green, 1 blue; 11 green, 6 red, 1 blue; 12 green, 2 red; 17 green, 1 blue, 14 red
Game 16: 3 red, 2 green, 5 blue; 1 green, 6 blue, 1 red; 1 green, 2 blue, 3 red; 1 blue, 1 red; 5 blue, 1 green, 2 red
Game 17: 3 blue, 6 red; 1 blue, 2 red; 1 blue, 1 green, 7 red; 1 green, 7 red, 2 blue; 7 red, 1 blue; 1 green, 8 red, 1 blue
Game 18: 6 green, 10 red; 6 red, 7 green; 10 red, 11 green; 10 red, 2 blue, 5 green
Game 19: 2 blue; 1 blue, 4 green, 6 red; 7 green, 6 red, 2 blue; 2 blue, 5 red, 4 green; 1 green, 10 red
Game 20: 6 red, 5 green, 10 blue; 5 blue, 5 green, 9 red; 7 blue, 3 green, 3 red; 9 blue, 12 red, 1 green
Game 21: 4 red, 18 blue, 14 green; 3 green, 14 blue, 5 red; 5 green, 12 blue; 1 blue, 2 red, 1 green; 5 red, 11 green, 7 blue; 17 green, 4 red, 15 blue
Game 22: 1 blue, 14 green, 4 red; 7 green, 10 red; 9 green, 1 blue, 9 red; 1 blue, 8 green, 5 red
Game 23: 4 blue, 5 green, 2 red; 6 blue, 8 red, 4 green; 4 blue, 17 red, 14 green
Game 24: 3 green, 8 blue; 3 blue, 5 green, 13 red; 17 red, 4 green
Game 25: 19 red, 9 blue, 1 green; 3 green, 18 red, 6 blue; 1 green, 7 red, 7 blue; 8 blue, 1 red
Game 26: 10 green, 12 blue, 2 red; 9 red; 10 blue, 12 green, 9 red
Game 27: 2 blue, 8 green, 6 red; 5 green, 9 red; 4 red, 11 green
Game 28: 10 blue, 20 red; 14 blue, 3 green, 2 red; 9 red, 12 blue, 1 green
Game 29: 4 red, 1 blue, 2 green; 1 green, 6 red, 1 blue; 15 red
Game 30: 1 red, 13 blue, 6 green; 3 blue, 4 green; 19 blue, 11 green; 1 red, 11 green, 14 blue
Game 31: 10 red, 12 green; 12 green, 10 red; 2 blue, 15 red, 12 green; 2 green, 2 blue, 15 red; 9 green, 5 red, 2 blue
Game 32: 5 blue, 5 green, 8 red; 5 green, 6 red; 5 blue, 8 red, 4 green; 5 green, 3 blue, 6 red
Game 33: 1 red, 9 green, 5 blue; 17 green, 4 blue; 3 green, 2 blue; 10 green, 2 blue; 1 blue, 4 green; 2 green, 9 blue
Game 34: 11 blue, 11 red, 9 green; 13 red, 3 blue, 5 green; 9 green, 12 blue, 5 red; 13 red, 8 blue, 5 green
Game 35: 1 green, 3 red, 7 blue; 1 red, 3 green, 9 blue; 1 blue, 2 green, 1 red; 11 blue, 5 red, 6 green
Game 36: 4 blue, 12 green, 16 red; 7 blue, 11 green; 8 green, 5 blue, 1 red; 14 green, 3 red
Game 37: 13 red, 5 blue, 9 green; 1 red, 10 blue, 14 green; 1 green, 2 blue, 10 red; 13 red, 10 blue; 1 blue, 8 green
Game 38: 3 red, 4 blue, 8 green; 1 red, 11 blue, 4 green; 13 blue, 8 green; 3 red, 3 green, 10 blue; 1 red, 1 blue, 1 green; 1 green, 2 red, 10 blue
Game 39: 9 red, 7 blue, 1 green; 15 red, 4 green, 1 blue; 2 green, 8 blue, 7 red; 6 blue, 11 red; 12 red, 2 blue, 7 green
Game 40: 13 red, 3 green, 1 blue; 3 green, 10 red; 16 red
Game 41: 1 blue, 3 red; 7 blue, 5 red, 3 green; 4 red, 3 blue, 2 green; 2 blue, 5 red, 1 green; 3 green, 4 red, 3 blue; 5 blue, 2 red
Game 42: 1 red, 4 green; 11 red, 4 green; 13 red; 1 blue, 10 red; 1 blue, 2 red, 4 green
Game 43: 11 green, 13 red, 1 blue; 11 green, 9 red, 2 blue; 7 green; 13 green, 15 red; 1 blue, 14 green
Game 44: 5 green, 14 blue, 15 red; 13 blue, 15 green; 9 green, 15 red, 6 blue
Game 45: 16 red, 8 blue; 1 green, 4 blue, 6 red; 4 blue, 8 red; 12 red, 3 blue, 3 green; 2 green, 4 red, 4 blue; 2 green, 8 blue, 10 red
Game 46: 12 blue, 3 green, 12 red; 9 red, 9 blue; 3 green, 12 red; 10 red, 6 green; 2 red, 7 blue
Game 47: 9 green, 6 red; 1 blue, 7 red, 10 green; 1 green, 2 red; 1 red, 3 green
Game 48: 9 blue, 5 green, 13 red; 14 green, 4 red; 15 red, 9 green, 1 blue; 4 blue, 6 red, 13 green; 9 green, 8 blue, 8 red
Game 49: 5 blue, 3 red; 1 green, 2 red, 5 blue; 1 green, 7 blue; 3 green
Game 50: 8 red, 6 green; 10 blue, 4 green, 6 red; 8 green, 11 blue, 9 red
Game 51: 5 blue; 13 blue; 1 red, 2 blue, 1 green; 1 red, 8 blue
Game 52: 7 blue; 1 red, 2 green, 12 blue; 1 red, 5 blue; 2 red, 7 blue, 4 green; 3 green, 2 red, 2 blue
Game 53: 10 blue, 12 red; 3 green, 5 blue, 3 red; 14 red, 4 green, 7 blue; 1 red, 14 blue
Game 54: 2 blue, 14 red, 3 green; 3 green, 7 red; 2 blue, 3 green, 9 red; 3 green, 7 red; 1 green, 14 red, 1 blue
Game 55: 3 green, 9 red, 12 blue; 5 blue, 5 green, 2 red; 7 green, 14 red, 12 blue
Game 56: 1 blue, 3 red, 4 green; 5 red, 8 green, 1 blue; 3 green, 1 blue, 2 red
Game 57: 8 blue, 13 red, 2 green; 3 blue, 5 red; 7 red, 2 green; 2 red, 5 blue, 3 green; 1 green, 4 blue
Game 58: 4 green, 3 red, 2 blue; 5 green, 2 blue, 10 red; 11 green, 1 red, 2 blue; 4 red, 5 green
Game 59: 5 green; 4 green, 2 blue; 1 red, 9 green; 7 green, 2 blue; 16 green, 1 blue
Game 60: 6 green, 5 blue, 1 red; 5 blue, 3 green, 6 red; 1 green, 5 blue, 14 red; 6 red, 4 blue, 3 green
Game 61: 2 green, 6 red, 6 blue; 6 blue, 3 red; 1 green, 2 red, 2 blue; 1 red, 2 green; 5 red, 1 green, 2 blue; 2 green, 6 red, 6 blue
Game 62: 18 green, 8 blue, 1 red; 8 green, 4 red; 13 blue, 1 red, 3 green; 7 blue, 2 green, 4 red; 4 blue, 12 green, 5 red; 12 green, 11 blue
Game 63: 2 red, 3 blue; 10 green, 13 red, 1 blue; 11 red, 3 green, 4 blue
Game 64: 1 green, 16 red; 17 blue, 9 red, 1 green; 14 red, 7 blue
Game 65: 7 blue, 11 red, 11 green; 7 red, 11 green; 3 blue, 13 red, 11 green; 5 green, 6 blue; 11 blue, 8 red, 3 green
Game 66: 3 blue, 1 green, 3 red; 5 blue, 2 green, 5 red; 1 blue, 2 green, 7 red; 2 blue, 6 red; 7 red, 2 green, 2 blue; 2 red
Game 67: 1 blue, 6 red, 2 green; 1 blue, 10 green, 6 red; 8 red, 2 blue, 4 green; 7 green, 9 red, 1 blue; 8 red, 7 green; 5 green, 1 blue
Game 68: 15 blue, 8 green, 2 red; 6 blue, 2 green; 5 red, 6 green, 8 blue; 6 red, 11 green, 7 blue; 1 red, 3 blue; 5 red, 6 green, 5 blue
Game 69: 5 blue, 4 green; 1 green, 11 red, 9 blue; 4 green, 15 blue, 6 red; 11 blue, 4 green, 5 red; 8 red, 3 green; 5 blue, 8 red
Game 70: 5 blue, 4 red, 8 green; 6 blue, 6 green; 14 blue, 7 red, 1 green; 2 green, 6 blue, 3 red; 7 red, 11 blue, 3 green
Game 71: 13 red, 6 blue, 10 green; 7 red, 12 green; 9 green, 14 red, 2 blue
Game 72: 9 red, 3 green, 3 blue; 8 red, 7 blue, 5 green; 3 blue, 2 green, 1 red; 1 red, 2 blue, 2 green; 10 red, 7 green, 6 blue
Game 73: 4 green, 3 red; 1 red; 2 red, 2 blue, 2 green; 1 blue, 3 red, 1 green; 2 blue, 3 red, 2 green; 1 red, 1 blue
Game 74: 12 green, 4 red, 4 blue; 3 red, 13 green; 1 red, 13 green, 1 blue; 1 red, 3 blue, 6 green; 6 blue, 5 red, 4 green; 7 blue, 5 green, 1 red
Game 75: 11 red, 1 green; 12 blue, 1 red; 2 blue, 1 green, 4 red; 11 red; 12 red, 6 green, 10 blue; 4 green, 5 blue, 7 red
Game 76: 2 blue, 5 red, 6 green; 1 red, 10 green, 11 blue; 7 red, 11 green; 4 red, 10 blue, 10 green; 7 blue, 16 green, 2 red
Game 77: 2 blue, 11 red, 4 green; 6 green, 3 blue, 2 red; 2 blue, 2 red, 7 green; 8 red, 14 blue, 5 green; 5 green, 2 blue, 18 red
Game 78: 9 red, 7 green, 6 blue; 12 blue, 6 red; 1 red, 15 blue, 7 green; 3 blue, 11 green, 1 red
Game 79: 3 blue; 1 blue; 1 red, 1 blue, 1 green; 3 blue; 5 blue, 1 red; 1 blue, 1 green, 1 red
Game 80: 18 blue, 13 green, 7 red; 18 blue, 3 green, 3 red; 2 red, 9 blue, 14 green
Game 81: 11 blue, 6 green, 3 red; 8 green, 12 red, 10 blue; 5 red, 4 blue, 13 green
Game 82: 2 blue, 3 red; 4 blue, 17 red; 9 red; 12 red; 1 green, 6 blue, 7 red; 20 red
Game 83: 1 blue, 1 red; 3 red, 1 blue; 3 red, 5 green; 1 blue, 2 green, 4 red; 5 green, 3 blue, 2 red
Game 84: 4 red, 2 blue, 2 green; 8 red, 10 blue; 1 green, 15 red, 8 blue
Game 85: 15 green; 11 red, 2 blue, 5 green; 8 red, 2 blue, 12 green; 15 red, 10 green; 10 red, 15 green; 17 red, 1 blue, 11 green
Game 86: 6 blue, 1 red; 2 green, 1 red, 8 blue; 2 green, 10 blue; 10 blue, 2 green; 1 red, 5 blue
Game 87: 4 red, 4 blue; 18 red, 8 blue; 16 red; 4 red, 1 green, 3 blue; 14 red, 9 blue
Game 88: 11 green, 7 blue, 4 red; 3 red; 2 blue, 12 red, 19 green; 13 red, 3 blue, 2 green
Game 89: 1 green, 1 red; 1 blue, 1 red, 6 green; 6 green, 3 red; 5 green, 2 red, 6 blue; 7 blue, 2 red, 8 green; 1 red, 2 blue
Game 90: 3 green, 3 red, 3 blue; 5 green, 2 blue, 3 red; 1 blue, 2 red; 11 green, 1 blue, 2 red; 1 green, 3 blue, 4 red
Game 91: 7 blue, 2 red; 2 blue, 1 red, 1 green; 6 blue, 1 red; 1 red, 7 blue
Game 92: 11 green, 16 blue; 17 red, 7 blue, 9 green; 11 green, 3 blue, 12 red; 2 blue, 1 green, 6 red
Game 93: 6 red, 1 blue, 3 green; 1 blue, 8 red, 7 green; 3 red, 5 green; 1 red, 2 green; 3 red, 7 green; 2 green, 15 red, 1 blue
Game 94: 7 blue, 2 red, 2 green; 9 blue, 4 red, 2 green; 9 blue, 5 red, 3 green; 1 blue, 4 red, 3 green; 4 red, 1 green, 7 blue; 9 blue, 3 green, 3 red
Game 95: 1 blue, 2 green, 2 red; 6 green, 6 red, 1 blue; 3 blue, 5 red, 2 green; 1 blue; 5 green, 2 red, 2 blue
Game 96: 3 blue, 6 red, 5 green; 5 blue, 8 green, 9 red; 2 red, 5 green, 1 blue; 6 green, 4 blue, 3 red; 2 green, 2 blue; 6 blue, 4 green
Game 97: 6 green, 8 blue, 5 red; 9 green, 6 blue; 3 green, 3 blue; 2 blue, 10 green, 4 red
Game 98: 11 blue, 1 green, 9 red; 5 green, 1 blue, 6 red; 13 blue, 6 green, 10 red; 6 blue, 4 green, 9 red
Game 99: 4 red, 3 green, 3 blue; 6 blue, 4 green, 11 red; 3 green, 15 red; 1 blue, 6 green, 14 red
Game 100: 14 green, 6 blue, 12 red; 2 green, 1 blue, 2 red; 12 red, 7 blue, 3 green; 1 blue, 12 red, 8 green
`;

const GAME_ID_REGEX = /^Game (\d+):/;
const SET_COUNT_REGEX = /(\d+) (red|green|blue)/g;

interface GameSet {
  red: number;
  green: number;
  blue: number;
}

interface Game {
  id: number;
  minimum: GameSet;
  sets: GameSet[];
}

function parse(input: string): Game[] {
  const games: Game[] = [];

  input.split("\n")
    .forEach((gameString) => {
      const idMatch = gameString.match(GAME_ID_REGEX);
      if (!idMatch) return;
      const game: Game = {
        id: parseInt(idMatch[1], 10),
        minimum: {
          red: 0,
          green: 0,
          blue: 0,
        },
        sets: [],
      };

      gameString = gameString.replace(GAME_ID_REGEX, "");
      gameString.split(";").forEach((setString) => {
        const gameSet: GameSet = {
          red: 0,
          green: 0,
          blue: 0,
        };
        Array.from(setString.matchAll(SET_COUNT_REGEX))
          .forEach((countMatch) => {
            const color = countMatch[2] as keyof GameSet;
            gameSet[color] = parseInt(countMatch[1], 10);
            game.minimum[color] = Math.max(game.minimum[color], gameSet[color]);
          });
        game.sets.push(gameSet);
      });

      games.push(game);
    });

  return games;
}

function isGameSetPossible(gameSet: GameSet, gameSetMax: GameSet): boolean {
  return (
    gameSet.red <= gameSetMax.red &&
    gameSet.green <= gameSetMax.green &&
    gameSet.blue <= gameSetMax.blue
  );
}

function isGamePossible(game: Game, gameSetMax: GameSet): boolean {
  for (const gameSet of game.sets) {
    if (!isGameSetPossible(gameSet, gameSetMax)) {
      return false;
    }
  }

  return true;
}

function calculateSumOfPossibleGameIds(
  input: string,
  gameSetMax: GameSet,
): number {
  let result = 0;

  const games = parse(input);
  for (const game of games) {
    if (isGamePossible(game, gameSetMax)) {
      result += game.id;
    }
  }

  return result;
}

function calculateSumOfPowersOfMinimumSets(input: string) {
  let result = 0;

  const games = parse(input);
  for (const game of games) {
    result += game.minimum.red * game.minimum.green * game.minimum.blue;
  }

  return result;
}

export function day02() {
  const partOneOutput = calculateSumOfPossibleGameIds(PUZZLE_INPUT, {
    red: 12,
    green: 13,
    blue: 14,
  });

  console.log(`Part One: ${partOneOutput}`);

  const partTwoOutput = calculateSumOfPowersOfMinimumSets(PUZZLE_INPUT);

  console.log(`Part Two: ${partTwoOutput}`);
}

Deno.test(function day02Test() {
  assertEquals(
    calculateSumOfPossibleGameIds(EXAMPLE_INPUT, {
      red: 12,
      green: 13,
      blue: 14,
    }),
    8,
  );
  assertEquals(
    calculateSumOfPossibleGameIds(PUZZLE_INPUT, {
      red: 12,
      green: 13,
      blue: 14,
    }),
    2369,
  );
  assertEquals(calculateSumOfPowersOfMinimumSets(EXAMPLE_INPUT), 2286);
  assertEquals(calculateSumOfPowersOfMinimumSets(PUZZLE_INPUT), 66363);
});
