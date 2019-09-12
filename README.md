# In Small Steps practice repository
Teaching myself programming in small steps. Each folder should be a FINISHED small project.

## WHAT IS THIS?
This is a collection of small applications. They don't serve any particular purpose, but rather they're just a way for me to develop my programming skills further.
Each folder in the root directory should contain a small and FUNCTIONING project.
If you see a "**(!!!FINISHED!!!)**" note near a project's name, it means exactly what it says, the project is finished. Otherwise if the note is absent it means the project is still in progress.
The real purpose here is to study some aspects of programming. The specific technologies and languages used are usually denoted in the project's description.
All the future apps in this project should be described here in this file.

## 1 - Calculator (MVC pattern)
A calculator based on Model-View-Controller pattern. It's written in C++ using the Qt framework.
The goal here is not to create a calculator per se, but to understand the basics of MVC and SOLID.
Calculator should contain a "Number" field, number buttons, a comma, equals sign, reset buttons, and the basic arithmetic operations (+,-,*,/).
Nothing fancy is expected here. Do this in MVC, follow SOLID/DRY where/if it makes sense to do so, and you're good to go.
When a change to the calculator is made, increment the 3rd number. When some feature is done, increment the 2nd number. When the whole project is done,
increment the 1st number.

**TO DO:**
  + **(DONE)** = sign works, but the sequence is incorrect. It should:
    a. Always perform the last operation available on the second operand;
  + **(DONE)** Operations buttons work, but one nuance is left:
    a. An operation button should push current input into result if pressed for the second time or more (but only once, after that it's just choosing an operation again);
  - **(DONE)** The "C" button should become "CE" (Clear Entry) as its current function is clearing the current input on display, which is usually done by the "CE" button;
  - **(DONE)** The "CA" button (Clear All) should be implemented. It clears everything;
  - **(DONE)** Introduce the floating point logic:
    a. '.' should only be pressable *once* per number;
    b. App should not crash and not lose the number if a '.' is the *last symbol* of the number;
    c. '.' pressed after 0 should be '0.', not '.'.
  - Implement keyboard key bindings for all the buttons.
  - **POSSIBLE BUG:** When you press CE and then /, the MS calculator throws the "cannot divide by zero" exception. This calculator currently just ignores it and continues the expression calculation without it. Have to find why the behaviors are different.
  - **BUG:** If you input a number of max precision (currently 13/26), the application sequencing breaks. Needs additional investigation;
  - **BUG:** Floating point logic has been implemented, but the precision on the floating point values is wonky. Currently the display shows values with the smallest possible precision, that's why display values are not always displayed with the necessary precision value.

## 2 - Effective Modern Cpp
This is a project created for the purpose of learning stuff from said book. Try to create a small program for each item to use it the way the book
wants you to, and to train the principle through practice.
Each item contains its own folder with a small project inside. When the project is updated, increment 3rd number. When the item is done, increment 
2nd number. When the whole book is done, increment 1st number.

## 3 - A TODO list application (!!!FINISHED!!!)
A TODO list application that features one list where the user can put TODO items with future tasks they'd like to remember to do.
The application is written in C# using the WPF framework. 

User Features:
+ **(DONE)** ListBox with a collection of CheckBoxes (each of CheckBoxes corresponds to one task to do).
+ **(DONE)** User can add new items.
+ **(DONE)** User can edit existing items.
+ **(DONE)** User can complete items (check the box on a CheckBox).
+ **(DONE)** User can uncomplete items (uncheck the box on a CheckBox).
+ **(DONE)** Drag and drop items to rearrange their positions.

Behind the scenes features:
+ **(DONE)** Completing an item should:
  a. Move the item to the bottom of the list
  b. Grey the item out
  c. Cross the item out
+ **(DONE)** Uncompleting an item should:
  a. Restore the item's color back to black
  b. Move the item up, to the bottom of the uncompleted part of the list
  c. Remove the strikethrough decoration.
+ **(DONE)** Saving the items to a simple JSON on application termination and restore the saved tasks on startup
+ **(DONE)** Provide keyboard shortcuts for all the operations stated above.


by Oleksii <DarkSpectre> Kshenskyi.
