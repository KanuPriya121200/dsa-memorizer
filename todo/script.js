const titleInput = document.getElementById("titleInput");
const linkInput = document.getElementById("linkInput");
const tagsInput = document.getElementById("tagsInput");
const difficultyInput = document.getElementById("difficultyInput");
const searchInput = document.getElementById("searchInput");
const todoList = document.getElementById("todoList");
const doneList = document.getElementById("doneList");

let problems = JSON.parse(localStorage.getItem("problems")) || [];

searchInput.addEventListener("input", renderProblems);

function renderProblems() {
  const query = searchInput.value.toLowerCase();
  todoList.innerHTML = "";
  doneList.innerHTML = "";

  problems.forEach((problem, index) => {
    if (
      problem.title.toLowerCase().includes(query) ||
      problem.tags.toLowerCase().includes(query)
    ) {
      const li = document.createElement("li");

      const link = document.createElement("a");
      link.href = problem.link;
      link.textContent = problem.title;
      link.target = "_blank";
      li.appendChild(link);

      const tagSpan = document.createElement("span");
      tagSpan.className = "tag";
      tagSpan.textContent = `Tags: ${problem.tags}`;
      li.appendChild(tagSpan);

      const diffSpan = document.createElement("span");
      diffSpan.className = "difficulty";
      diffSpan.textContent = `Difficulty: ${problem.difficulty}`;
      li.appendChild(diffSpan);

      const doneBtn = document.createElement("button");
      doneBtn.textContent = problem.completed ? "Undo" : "Done";
      doneBtn.onclick = () => {
        problem.completed = !problem.completed;
        saveProblems();
        renderProblems();
      };
      li.appendChild(doneBtn);

      const deleteBtn = document.createElement("button");
      deleteBtn.textContent = "×";
      deleteBtn.className = "delete-btn";
      deleteBtn.onclick = (e) => {
        e.stopPropagation();
        problems.splice(index, 1);
        saveProblems();
        renderProblems();
      };
      li.appendChild(deleteBtn);

      if (problem.completed) {
        doneList.appendChild(li);
      } else {
        todoList.appendChild(li);
      }
    }
  });

  updateProgress();
}

function addProblem() {
  const title = titleInput.value.trim();
  const link = linkInput.value.trim();
  const tags = tagsInput.value.trim();
  const difficulty = difficultyInput.value;

  if (!title || !link) return;

  problems.push({ title, link, tags, difficulty, completed: false });
  saveProblems();
  renderProblems();

  titleInput.value = "";
  linkInput.value = "";
  tagsInput.value = "";
  difficultyInput.value = "";
}

function saveProblems() {
  localStorage.setItem("problems", JSON.stringify(problems));
}

function updateProgress() {
  const doneCount = problems.filter(p => p.completed).length;
  const totalCount = problems.length;
  const percent = totalCount === 0 ? 0 : Math.round((doneCount / totalCount) * 100);

  document.getElementById("progress").textContent = `Completed: ${doneCount}/${totalCount}`;
  document.getElementById("progress-bar").style.width = percent + "%";
}

renderProblems();

