## Notes for reviewers

The debian package which satisfies the basic requirements of this assignment can be downloaded here: [v1.0](https://github.com/hawthorne3341/codetest/releases/tag/1.0)

The debian package satisfying both the basic requirements as well as the bonus assignment can be downloaded here: [v1.1](https://github.com/hawthorne3341/codetest/releases/tag/1.1)

The command is called ```mysl```, and per the requirements accepts an ```-n N``` flag which displays the nth animation. If no ```-n``` flag is present, a random animation is displayed.

Additionally, the command accepts a ```-w``` flag which writes the contents of a random file from the ```assets``` directory to the current working directory in which the
command is run.

Both versions are available as apt style repo packages and can be run on Ubuntu 20.04 or newer

The unit tests for the application depend on [Criterion](https://github.com/Snaipe/Criterion)
