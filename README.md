# Encapsulate the image

This project is a first attempt at keeping the image along with its functionality.

## What's done

The code tries to retain image-related functionality in one place (the `Image` struct).
The first step is to avoid consumers having to worry about managing the pixel memory lifetime.

This is achieved by doing two things:
- The `Image` structure now has a destructor to free the pixel memory
- The `ImageBrightener` class now accepts a `unique_ptr`, so clients need to "move" their responsibility of the image to the brightener

## What's remaining

Of course, everything can be improved, so let's improve this as well :)

---

**Bring functionality together**:

Assume that in this domain, any image must not exceed 1024 rows or columns.
This is expressed in a comment within the `Image` struct.
However, the actual functionality to validate the image is in the `ImageBrightener`.
Move the validation into the `Image` structure, so that it remains a property of the `Image`.

---

**Try shared responsibility**:

Notice that once the `main()` hands over responsibility, it can no longer access the brightened image.

Resolve this, so that it can access the image after calling the brightener.
Hint: Use shared_ptr

---

**Improve**:

Improve the code that you aren't modifying as well. E.g., remove all commented code.
If you need older code, it will be present in the GitHub history
