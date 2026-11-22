# WATERWISE – Testing Evidence

The sample program run uses clearly labelled simulated readings. The following cases should be tested and screenshots should be captured from the terminal/compiler for final submission.

| No. | Test case | Test input / condition | Expected behaviour |
|---:|---|---|---|
| 1 | Normal readings | Valid readings and targets for all five zones | Correct weekly total, average, peak reading and earliest peak day. |
| 2 | Over-limit days | One or more readings strictly above the zone target | Count only those days; excess is the sum of reading minus target on those days. |
| 3 | Sudden spike | Previous day 1,000 L; current day 1,401 L | Current day is flagged as a spike. |
| 4 | Exactly 40% rise | Previous day 1,000 L; current day 1,400 L | Not flagged as a spike because the comparison is strictly greater than 1,400. |
| 5 | Over-limit + spike | One day satisfies both conditions | Count it once in unique alert days. |
| 6 | Tied zone ranking | Two zones have equal total excess | Both zones display the same rank and both appear in the greatest-excess list if tied for highest. |
| 7 | No alerts | All readings within target and no rise greater than 40% | Zero alert days and maintain-good-practices recommendation. |
| 8 | Invalid input | Negative reading, reading above 50,000, target below 100 or above 50,000 | Reject the value and request it again. |

## Additional menu checks

- Select option 3 before option 2: program must ask the user to generate the audit report first.
- Select option 4 before option 2: program must ask the user to generate the audit report first.
- Enter a menu choice outside 1–5: program must show an invalid-choice message and display the menu again.

**Evidence reminder:** Add your own terminal screenshots in this folder before submitting. The sample output is not a substitute for screenshots of your own execution.
