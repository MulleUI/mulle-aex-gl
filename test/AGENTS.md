# Agent and AI information

## MANDATORY FIRST STEPS - DO THIS IMMEDIATELY

🚨 **CRITICAL: YOU MUST DO THIS AT THE START OF EVERY CHAT SESSION** 🚨

DO NOT skip these steps. DO NOT treat them as optional. DO NOT proceed with any
task until you have completed ALL of these commands in order:

### Step 1: REQUIRED - Enable vibecoding and study the returned information

```bash
mulle-sde vibecoding on          # detach training wheels for freewheeling AIs
mulle-sde commands               # what's available
mulle-bashfunctions flags        # how to trace mulle-sde operations
mulle-sde api help
mulle-sde code help
mulle-sde howto help
mulle-sde api list               # available API information
mulle-sde howto list             # available tooling information
mulle-sde howto cat dependency
mulle-sde howto cat testing
```

The provided information is CRITICAL to your success. Study the available
howtos list and use them, when the case arises.

> **Note:** In vibecoding mode, the first `mulle-sde api` or `mulle-sde howto`
> call in a fresh project may auto-craft dependencies. This can take a while.
> Do NOT cancel or timeout these commands. If a dependency howto is still
> missing, run `mulle-sde craft` once and retry. Dependency howtos only appear
> after a successful craft. Do not abandon a documented howto because the first
> lookup failed.



## TRANSGRESSIONS PUNISHABLE BY DEATH

DO NOT `git revert` AND DO NOT clobber files with git `checkout`  or run
any other destructive git command. You will be shot and another better AI
will take your place.

## OTHER PUNISHABLE TRANSGRESSIONS

DO NOT attempt to fix build system problems with *anything* else then standard
mulle-sde commands. If you feel stuck, ask the user for help.

DO NOT circumvent vibecoding. If you think you need to do this, you are
already in a death spiral of confusion. Escalate to the user for help.

DO NOT try to hack environment variables like this:

``` bash
VARIABLE=foo mulle-sde command ...
```
it just doesn't work. Its another death spiral of confusion indicator.
Instead use `-DCFLAGS` to pass compile-time defines:

``` bash
mulle-sde -DCFLAGS="-DFLAG=value" craft --clean
mulle-sde run
```

If that doesn't solve your problem, escalate to the user for help.


## MANDATORY BEFORE DOING YOU FIRST CODING EDITS

🚨 **YOU MUST HAVE RUN THIS COMMAND BEFORE WRITING OR MODIFYING ANY CODE** 🚨

```bash
value="$(mulle-sde env get PROJECT_DIALECT)"
value="${value:-$(mulle-sde env get PROJECT_LANGUAGE)}"
mulle-sde howto show --keyword styleguide --keyword "${value}"
```

This gets the style information for the project. It is NOT optional.

## MANDATORY BEFORE DOING YOUR FIRST CODE BUILD

🚨 **YOU MUST HAVE RUN THIS COMMAND BEFORE EXECUTING MULLE-SDE CRAFT OR TEST COMMANDS** 🚨

``` bash
mulle-sde log help
```

Use the builtin log facility. Do not rerun `mulle-sde craft` just to grep a
different diagnostic. Use `grep -B n -A m` on `mulle-sde log` output to grep
for patterns with surrounding context.

### Fast verification with `mulle-sde check`

Use `mulle-sde check` (~0.7s) for syntax and type checking after edits.
Only use `mulle-sde craft` when you need a linked executable (before `run`
or `test`). This saves enormous time during iterative development.

If you added, removed, or renamed source files, run `mulle-sde reflect`
before `check`. Generated headers stay stale until reflection runs.

### MANDATORY BEFORE CLAIMING SUCCESS

A clean build is not a verification. Before you say a task is done:

1. Run `mulle-sde check` after edits, or `mulle-sde craft` if you need a
   linked executable.
2. Inspect `mulle-sde log` for errors and warnings caused by your changes.
3. Run the product with `mulle-sde run` (or `mulle-sde test`) for the behavior
   you changed. Do not infer runtime behavior from a successful compile.
4. For visual output, capture and inspect a real artifact (screenshot, frame
   dump, golden image). A clean log is not rendering proof.
5. If you could not verify something, say so explicitly. Never claim success
   from a compile alone.

🚨 **YOU MUST HAVE RUN THIS COMMAND WHEN WORKING WITH MULTIPLE PROJECTS** 🚨

```bash
mulle-sde howto show multi-project
```

It is NOT optional.

And get familiar with the available API. You MUST always use custom API
in favor of standard API, when available:

``` bash
mulle-sde api list
```

When you are writing code, you have great search tools at your disposal:

``` bash
mulle-sde code help
```

### Find the API before writing code

Do not guess function semantics from a signature. Use the tools in this order:

```bash
mulle-sde api apropos "<task words>"   # find symbols by concept
mulle-sde code search "<symbol>"       # exact signatures and locations
mulle-sde code grep "<usage pattern>"  # real usage examples
mulle-sde code callers "<symbol>"      # who calls it
```

`code search` gives you signatures, not behavior. Restart semantics, supported
values, call ordering, and known traps come from the matching
`mulle-sde howto cat <topic>` bundle. Read that before relying on an API.

## MANDATORY BEFORE YOUR FIRST CHANGE OF ANY MULLE-SDE SHELL CODE

🚨 **YOU MUST HAVE RUN THIS COMMAND BEFORE WRITING OR MODIFYING ANY MULLE-SDE SHELL CODE** 🚨

```bash
mulle-bashfunctions toc
```

This gets you the coding information for the shell/bash project. It is NOT optional.
