# Table of Contents
- [Style Guidelines](#style-guidelines)
- [Testing](#testing)
- [Quality](#quality)


# Style Guidelines

Install pre-commit hook once cloned from this repository.
Apart of other checks it will mainly auto-format source code, check
for trailing whitespaces and fix end of lines.

```bash
# install hook for upcoming commits
pre-commit install

# run pre-commit checks manually on all files
pre-commit run --all-file
# only on staged files
pre-commit
```

The procedure:
1. make code changes
2. stage files
3. git commit
   1. pre-commit check succeedes -> commit is done
   2. pre-commit check fails -> commit is interrupted
      1. files are changed and unstaged
      2. review changes, stage files and repeat the commit command

The project comes with its own `.clang-format` file.
Do auto format and let the auto-formatter decide.
If auto formatting is forgotten, the pre-commit hook will finally do it.
In doubt apply the do-not-harm principle:
stick to the same pattern as the majority of the code does.


# Testing

- Prefer unit tests over integration tests.
- For each PR tests must exist that prove the changes.
- Old tests must be updated if they fail.
- Prior a PR run unit tests on as many platforms you are able to
(native, atmelavr, ststm, espressif, ...).


# Quality

- Always assume the code is compiled with `-Wall -Werror`.
- Your changes shall not procude new warnings.
- If you can fix old warnings please do so.
- Perform a self-review, comment code in public interface
and in hard-to-understand areas.
- Update the documentation accordingly.
