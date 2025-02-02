# cc-rules

A set of please rules for compiling C and C++ code that are meant to be compatible with the official cc-rules.

These rules are meant to be close enough to the official ones so that you can reference the documentation for the offical cc-rules. However, there may still be a lot of unimplemented features that the official rules provide.

Please note that this project has grown on an as-needed basis and as such may not support more uncommon aspects of C++ compilation. As projects that rely on these rules mature and use more niche C++ compilation features, so should this repository.

## Official please version not yet supported:

The official please version is not supported, as it misses some handling of pre- and post-build steps. If you would like use these rules, it is currently required to use [this branch of a fork](https://github.com/cemeceme/please/tree/singe-output-labels) that implements this, until the official releases provide better support.

## Main design goals

* To stay close to drop-in compatible with the official cc-rules.
* Move compiler specific aspects into their own rules.
* The ability to use multiple different compilers in the same project.
* Make the defining of new compilers simple.
* Provide a means of better handling of shared object dependencies.
* Allow for the compiling of generated sources in multiple parallel steps.

In general, the official cc-rules impose limitations on which compilers can be used in a project. Mainly this is because they have some hard coded parameters that may be incompatible with compilers other than gcc. Also, they don't provide an easy way of using multiple different compilers in the same project.

By contrast, these rules are meant to support different compiler "modules", where the rules themselves are mostly an interface to call back to compiler specific rule implementations.

This way, new compilers with incompatible parameters should be able to be used with minimal changes to the projects using these rules. Note however, with the way these rules are written, they impose a Compile->archive->link pipeline.

## Switching from the official plugin
Switching from the official cc-rules is fairly simple, with two simple edits:
- Replace the plugin definition.
- Edit your `plzconfig` file.
- Make sure you have a please version installed that is supported, as mentioned aove.

### Replacing the plugin definition
If you are using the `cc-rules` plugin, there should be a section in your plugins build file that looks like this:
```
plugin_repo(
    name = "cc",
    plugin = "cc-rules",
    revision = "v1.0.0"
)
```

Change the cc plugin definition to instead include these two plugins instead:
```
plugin_repo(
    name = "cc",
    revision = "master",
    plugin = "cc-rules",
    owner = "cemeceme",
)

plugin_repo(
    name = "gcc",
    revision = "master",
    plugin = "gcc-cc-rules",
    owner = "cemeceme",
)
```

This will replace the cc-rules to use this repos version instead and use the gcc rules module as the compiler. This setup should be the most compatible with the official rules.

Next, edit your `.plzconfig` file to properly use the correct plugins.
You should have a section for the original cc plugin with the following form:
```
[Plugin "cc"]
Target = //plugins:cc
; list of cc-rule parameters
```

Instead, edit it to be in the form of:
```
[Plugin "cc"]
Target = //plugins:cc
DefaultCCompilerPlugin = ///gcc//build_defs:gcc
DefaultCPPCompilerPlugin = ///gcc//build_defs:gpp

[Plugin "gcc"]
Target = //plugins:gcc
; list of cc-rule parameters
```
Note that the cc-rule configuration parameters are now grouped under the gcc plugin, as it is individual compiler modules to handle compiler specific configurations. In this case, the gcc plugin now handles the cc rules that were defined previously.

And with that, you should now be able to build your project as usual!