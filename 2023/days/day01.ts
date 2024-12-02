import { assertEquals } from "@std/assert";

export function day01() {
  console.log("hello world");
}

Deno.test(function day01Test() {
  assertEquals(day01(), undefined);
});
