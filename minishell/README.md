# Minishell

*This project has been created as part of the 42 curriculum by asgalean and cvon-hee.*

---

## Description

Minishell is a custom Unix shell written in C that replicates the core behavior of bash. It reads a command line, tokenizes and parses it into a command tree, then walks that tree to execute the result — handling pipes, redirections, environment variables, quoting, and a set of built-in commands. It's built on top of a custom `libft` and uses the GNU `readline` library for line editing and history.

Key features:
- Custom lexer/parser that builds a command tree out of typed nodes (`t_execcmd`, `t_pipecmd`, `t_redircmd`, `t_heredoccmd`, `t_listcmd`)
- Pipes (`|`) and command lists (`;`, `&&`, `||`) with proper left-to-right, short-circuit evaluation
- Redirections: `<`, `>`, `>>`, and heredocs (`<<`), including `SIGINT` handling mid-heredoc
- Environment variable expansion (`$VAR`, `$?`) inside unquoted, single-quoted, and double-quoted tokens
- Built-in commands: `cd`, `echo`, `env`, `exit`, `export`, `pwd`, `unset`
- External command execution via `execve`, resolving the binary against `$PATH`
- Signal handling matching bash: `Ctrl-C` clears the current line and redraws the prompt, `Ctrl-\` is ignored
- `$SHLVL` tracking and a colorized custom prompt (`user@minishell:~/path$ `)

---------------

## Instructions

### Requirements

- Linux
- GNU `readline` development headers (`sudo apt install libreadline-dev` on Debian/Ubuntu)

### Compilation

```bash
make
```

This builds `libft` and then compiles minishell into the `minishell` executable.

```bash
make clean   # remove object files
make fclean  # remove object files + binary + libft
make re      # full rebuild
```

### Execution

```bash
./minishell
```

This drops you into an interactive prompt where you can run commands as in any POSIX shell:

```bash
echo "hello $USER" | grep hello
ls -la && pwd || echo "command failed"
cat << EOF
type some text, then Ctrl-D to end
EOF
```

---------------

## Notes

`is_builtin` / `is_valid_builtin` recognize exactly the seven built-ins listed above — anything else is resolved as an external binary via `$PATH`. A background operator (`&`) type exists in the grammar definitions but isn't wired into execution, so `&` is not currently supported as a job-control operator.
