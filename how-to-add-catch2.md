## How to add Catch2 test framework to an existing solution in Visual Studio

### 1. Create a test project in the same solution as the code you want to test.

To add a new test project to an existing solution, right-click on the Solution node in **Solution Explorer**. In the pop-up menu, choose **Add** > **New Project** > **Empty Project**.

### 2. Add a reference to the project under test in your test project.

Right-click on the test project node in **Solution Explorer** for a pop-up menu. Choose **Add** > **Reference**. In the Add Reference dialog, choose the project you want to test.

### 3. Link the tests to the project's under test object files:

1. In Solution Explorer, on the shortcut menu of the test project, choose **Properties**. The project properties window opens.
2. Select **All Configurations** in Configuration menu and **All Platforms** in Platform menu.
3. Select the **Configuration Properties** > **Linker** > **Input** page, then select **Additional Dependencies**.

	Choose **Edit**, and add the names of the **.obj** files (**.obj** files of the project under test), which are used in tests. Don't use the full path names.

	**For example**, if you to want to test the code declared in *Task.h* and *Approach.h*, put *Task.obj* and *Approach.obj* here.

	**Note**: When you reference more header files from the project under test, don't forget to update this setting.

4. Select the **Configuration Properties** > **Linker** > **General page**, then select **Additional Library Directories**.

	Choose **Edit**, and add the directory path to **.obj** files of the project under test. The path is typically within the build folder of the project under test.

	**For example**, you can put here:
	
	$(OutDir) // not sure if this example is applicable in all cases

	**Hint**: Use macros here. See the list of macros with their meanings [here](https://docs.microsoft.com/en-us/cpp/build/reference/common-macros-for-build-commands-and-properties?view=vs-2019).

5. Select the **Configuration Properties** > **VC++ Directories** page, then select **Include Directories**.

	Choose **Edit**, and then add the header directory of the project under test.
	
	**For example**, you can put here:
	
	../project-under-test
	
	**Hint**: Use realtive path here, not absolute.	

### 4. Include directories of the project under test to the test project:

To avoid having to type the full path in each include statement in source files of the test project, you can add the required folders in **test project** > **Properties** > **C/C++** > **General** > **Additional Include Directories**.

**For example**, you can put here:

../project-under-test

**Hint**: Use realtive path here, not absolute.	

So now instead of writing in the test project like so:

	#include "../project-under-test/Task.h" 

you can write in this way:

	#include "Task.h"

### 5. Add catch.hpp file to the test project folder.

Get it from [here](https://raw.githubusercontent.com/catchorg/Catch2/master/single_include/catch2/catch.hpp).

### 6. Create a tests-main.cpp file in the test project and add the lines below:

	#define CATCH_CONFIG_MAIN
	#include "catch.hpp"

### 7. Write some tests.

You can have as many source files with tests as you want, but remember that only one of them must have the **#define CATCH_CONFIG_MAIN** declaration.

## References:

<https://stackoverflow.com/questions/59645381/best-practices-for-unit-testing-with-catch2-in-visual-studio>

<https://docs.microsoft.com/en-us/visualstudio/test/writing-unit-tests-for-c-cpp?view=vs-2019>

<https://docs.microsoft.com/en-us/visualstudio/test/how-to-use-microsoft-test-framework-for-cpp?view=vs-2019#object_files>
