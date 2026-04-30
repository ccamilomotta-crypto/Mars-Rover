// provided. do not modify. do not submit.
#ifndef PROVIDED_ROVER_H_
#define PROVIDED_ROVER_H_

#include "MyString.h"

class Rover {
    MyString smile_;

 public:
    /**
     * Construct a new Rover.
     * SMILE data is initially empty.
     *
     * @note Uses the `MyString` converting constructor (from c-string)
     */
    Rover() : smile_{""} {}

    /**
     * Construct a a new Rover.
     *
     * @param smile initial SMILE data
     * @note Uses the `MyString` copy constructor
     */
    explicit Rover(MyString smile) : smile_{smile} {}

    /**
     * The SMILE data.
     */
    MyString smile() { return smile_; }

    /**
     * Set the SMILE data to `smile`.
     *
     * @param smile the new SMILE data
     * @note Uses the `MyString` copy assignment operator
     */
    void set_smile(MyString smile) { smile_ = smile; }

    /**
     * Print the SMILE data to standard output.
     */
    void print();

    /**
     * Read the SMILE data value at `index`.
     */
    void read(int index);

    /**
     * Make the SMILE data empty.
     */
    void clear();

    /**
     * Append the given SMILE data and save.
     */
    void join(MyString data);

    /**
     * Append the given SMILE data but don't save.
     *
     * @returns the result of the append operation
     */
    MyString test(MyString data);

    /**
     * Find the given SMILE data.
     *
     * @returns `true` if the data was found.
     */
    bool find(MyString data);
};

#endif  // PROVIDED_ROVER_H_
