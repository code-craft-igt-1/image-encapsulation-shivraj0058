# Encapsulate the image

This project is a first attempt at keeping the image along with its functionality.

## What's done

The code tries to retain image-related functionality in one place (the `Image` struct). It also tries to use `unique_ptr` to express ownership of the image.

However, it tries accessing the image after "handing it over" to the `ImageBrightener`. Such access results in a runtime error.

## Your task

**Bring functionality together**:

Assume that in this domain, any image must not exceed 1024 rows or columns.
This is expressed in a comment within the `Image` struct.
However, the actual functionality to validate the image is in the `ImageBrightener`.
Move the validation into the `Image` structure, so that it remains a property of the `Image`.

---

**Try clear ownership**:

Notice that once `main()` hands over ownership, it can no longer access the brightened image.

Resolve this, so that it can access the image after calling the brightener.

Hint: Two possible ways- Either change the brightener into a plain function, so it does not need to take over ownership. Or, use `shared_ptr`
