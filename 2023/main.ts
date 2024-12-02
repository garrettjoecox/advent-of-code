import { day01 } from "./days/day01.ts";
import { day02 } from "./days/day02.ts";
import { day03 } from "./days/day03.ts";

const days = [
  day01,
  day02,
  day03,
];

if (import.meta.main) {
  if (Deno.args.length < 1) {
    console.error("Usage: ./advent <day>");
    Deno.exit(1);
  }

  const day = parseInt(Deno.args[0], 10);

  if (Number.isNaN(day)) {
    console.error("Invalid day");
    Deno.exit(1);
  }

  if (day < 1 || day > days.length) {
    console.error("Invalid day");
    Deno.exit(1);
  }

  days[day - 1]();
}
