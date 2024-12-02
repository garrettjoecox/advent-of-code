import { assertEquals } from "@std/assert";

const EXAMPLE_INPUT_PART_ONE = `
`;

const EXAMPLE_INPUT_PART_TWO = `
`;

const PUZZLE_INPUT = `
`;

function doTheThing(input: string): number {
  let result = 0;

  return result;
}

export function day__() {
  const partOneOutput = doTheThing(PUZZLE_INPUT);

  console.log(`Part One: ${partOneOutput}`);

  const partTwoOutput = doTheThing(PUZZLE_INPUT);

  console.log(`Part Two: ${partTwoOutput}`);
}

Deno.test(function day__Test() {
  assertEquals(doTheThing(EXAMPLE_INPUT_PART_ONE), undefined);
  assertEquals(doTheThing(PUZZLE_INPUT), undefined);
  assertEquals(doTheThing(EXAMPLE_INPUT_PART_TWO), undefined);
  assertEquals(doTheThing(PUZZLE_INPUT), undefined);
});
